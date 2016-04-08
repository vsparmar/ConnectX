/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"
#include "ConnectX.cpp"

class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

// Not possible to verify the variables used in this function because they are 'Private', as declared in the 'ConnectX.h' file.
//TEST(ConnectXTest, connectXInitial){
//
//    ConnectX c;
//    EXPECT_NO_THROW(ConnectX(-1,-1,-1));
//    EXPECT_EQ(7, wide);
//    EXPECT_NO_THROW(ConnectX(2,2,2));
//    EXPECT_NE(2, wide);
//}

//Test to verify if it accepts the positive position and rejects positions larger than established.
TEST(ConnectXTest, atPositive){

    ConnectX c;
    ASSERT_EQ(0, c.at(1,1));
    ASSERT_EQ(0, c.at(0,1));
    ASSERT_EQ(0, c.at(1,0));
    ASSERT_EQ(-1, c.at(5,7));
    ASSERT_EQ(-1, c.at(8,4));//Failed test, it should ignore this position, but it is accepting a position from outside the board dimensions.
}

//Test to verify if the negative position is descarded.
TEST(ConnectXTest, atNegative){

    ConnectX c;
    ASSERT_EQ(0, c.at(-1,5)); //Failed test, should ignore this position, but it's accepting a position from out of the board dimension.
    ASSERT_EQ(-1, c.at(1,-2)); 
    ASSERT_EQ(-1, c.at(-1,-3));
}

//Test to show board (unable to verify if the board is correctly filled with the values)
TEST(ConnectXTest, ShowBoardInfo){

    ConnectX c;

    EXPECT_NO_THROW(c.showBoard());
    EXPECT_NE("  ", std::cout);

}

//Test to populate the board (it's not possible to do the test because the used variables are 'Private', so there isn't a way to verify it's
// content in this unit test, but, as this function uses inBounds, if a invalid parameter is informed in the 'Colum' field, as, for example,
// '8', '-1', etc, the program will accept it as a valid position. 
//TEST(ConnectXTest, PlacePiecePos){
//
//    ConnectX c;
//
//    EXPECT_NO_THROW(c.placePiece(2));
//    EXPECT_EQ(" ", c.board);
//
//}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
