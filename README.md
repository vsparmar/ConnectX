Name: Vijay Parmar

1- Bug - 'Width' field

The main problem found is occuring in the 'width' field. Even if a problem is identified, 
the program moves on to verifying the 'height' field, and if there are no isseus found, 
it accuses the entry parameters as valid. To correct this bug it would be necessary to include a 
command, such as return, for example, so that as soon as a problem is detected, it will force 
the method to exit. 

  1.1- Secondary issues

As a result of the bug, there were two test failures, which are described in the test case.
I also found two tests that I was unable to execute correctly as the variables were set to 'Private'. 






