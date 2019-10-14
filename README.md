Dynamically Allocating Video Objects
Allows the user to specify up to 100 videos. If more than 100 videos are specified, print the message “Too many videos, giving up.” and a newline (endl) to “Standard Error” (using cerr) and terminate the program.
Return an exit status of 0 (from your main function) if there are no errors, 1 if there are any error conditions detected.
Use an array of pointers to videos (Video*) to store the videos. Use dynamic memory (the “new” operator) to create a new Video object for each description read. Don’t forget to use the “delete” operator to free each dynamic allocation before the program exits.
