# Notes

## pthread_create
* meaning of four parameters
  * 1st : address of pthread_t variable
  * 2nd : custom attributes, NULL means default
  * 3rd : entry function/code (function pointer)
  * 4th : arguments to entry function (void*)

## pthread_join
  * block current thread till completion of specified thread
  * collect exit status of terminated thread
