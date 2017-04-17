# mini_library_call_monitor

Environment
-----------
gcc (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609

Install
-------

Please put the project in linux base environment.
It is very important thing!!!!!!!!!

Just put command `make` then you will get hw2.so.

How to run
----------

`MONITOR_OUTPUT=<filename or stderr> LD_PRELOAD=./hw2.so <some command>`

If you put `stderr`, the output will put on the screen. 
Or the output will put in the file.

There are 77 functions I monitor.

The basic is below:
closedir fdopendir opendir readdir readdir_r rewinddir seekdir telldir   creat 
open     remove    rename  setbuf  setvbuf   tempnam   tmpfile tmpnam    exit
getenv   mkdtemp   mkstemp putenv  rand      rand_r    setenv  srand     system
chdir    chown     close   dup     dup2      _exit     execl   execle    execlp
execv    execve    execvp  fchdir  fchown    fork      fsync   ftruncate getcwd
getegid  geteuid   getgid  getuid  link      pipe      pread   pwrite    read
readlink rmdir     setegid seteuid setgid    setuid    sleep   symlink   unlink
write    chmod     fchmod  fstat   lstat     mkdir     mkfifo  stat      umask

And I choose 5 functions:

In stdilb: 
realloc, fputs_unlocked, abs, atoi

In stdio:
fflush

The reason I choose fflush, realloc and fputs_unlocked is because I can see the answer easily on teacher's page.
And the reason I choose abs and atoi is because the two function is very useful and I use them lots of time.
