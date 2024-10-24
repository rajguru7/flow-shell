* stdin is a stream. It is transient. Cannot maintain an offset for something
  that happened in time. Time cannot go backward. It does not support random
  access.
* Other files on disk have an offset maintained by the kernel. It is in space
  not time, hence possible.
* fgets creates a FILE (stream) from the file (disk). Every FILE object
  created by fopen a stream. So fopen, fgets etc allow you to treat that
  chunk of file on disk (space) as a stream (time).
