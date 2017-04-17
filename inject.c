#include <dlfcn.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define S static
#define mo "[monitor]"
#define dl dlopen("libc.so.6", RTLD_LAZY)
#define xd(a,b)({if(!a){void *ptr=dl; if(ptr) a=dlsym(ptr,#b);}})
#define p(a,...) { fprintf(stderr,"[monitor] "); fprintf(stderr,a,__VA_ARGS__); } 

S void (*old__exit)(int status) = NULL;

void _exit(int status) {
	xd(old__exit,_exit);
	p("%s(%d)\n", "_exit", status);
	old__exit(status);
}
S int (*old_chdir)(const char *path) = NULL;

int chdir(const char *path){
	xd(old_chdir,chdir);
	int tmp = old_chdir(path);
	p("%s('%s') = %d\n","chdir", path, tmp );
	return tmp;
}

S int (*old_chmod)(const char *pathname, mode_t mode) = NULL;

int chmod(const char *pathname, mode_t mode) {
	xd(old_chmod,chmod);
	int tmp = old_chmod(pathname, mode);
	p("%s(%s, %d) = %d\n", "chmod",pathname, mode, tmp );
	return tmp;
}

S int (*old_chown)(const char *pathname, uid_t owner, gid_t group) = NULL;

int chown(const char *pathname, uid_t owner, gid_t group) {
	xd(old_chown, chown);
	int tmp = old_chown(pathname, owner, group);
	p("%s(%s,%d,%d) = %d\n","chown", pathname, owner, group, tmp);
	return tmp;
}

S int (*old_close)(int fd) = NULL;

int close(int fd){
	xd(old_close, close);
	int tmp = old_close(fd);
	p("%s(%d) = %d\n","close", fd, tmp);
	return tmp;
}

S int (*old_closedir)(DIR *dirp) = NULL;

int closedir(DIR *dirp){
	xd(old_closedir,closedir);
	int tmp = old_closedir(dirp);
	p("%s(%p) = %d\n","closedir",dirp,tmp);
	return tmp;
}

S int (*old_creat)(const char *path, mode_t mode) = NULL;

int creat(const char *path, mode_t mode){
	xd(old_creat, creat);
	int tmp = old_creat(path, mode);
	p("%s(%s, %d) = %d\n","creat", path, mode, tmp);
	return tmp;
}

S int (*old_dup)(int oldfd) = NULL;

int dup(int oldfd) {
	xd(old_dup,dup);
	int tmp = old_dup(oldfd);
	p("%s(%d) = %d\n","dup",oldfd, tmp);
	return tmp;
}

S int (*old_dup2)(int oldfd, int newfd) = NULL;

int  dup2(int oldfd, int newfd) {
	xd(old_dup2, dup2);
	int tmp = old_dup2(oldfd, newfd);
	p("%s(%d, %d) = %d\n","dup2",oldfd,newfd,tmp);
	return tmp;
}

S int (*old_execl)(const char *path, const char *arg, ...) = NULL;

int execl(const char *path, const char *arg, ...) {
}

S int (*old_execlp)(const char *file, const char *arg, ...) = NULL;

int execlp(const char *file, const char *arg, ...) {
}

/*
S int (*old_execle)(const char *path, const char *arg, ..., char * const envp[]) = NULL;

int execle(const char *path, const char *arg, ..., char * const envp[]) {
}
*/

S int (*old_execv)(const char *path, char *const argv[]) = NULL;

int execv(const char *path, char *const argv[]) {
}

S int (*old_execvp)(const char *file, char *const argv[]) = NULL;

int execvp(const char *file, char *const argv[]) {
}

S int (*old_execvpe)(const char *file, char *const argv[], char *const envp[]) = NULL;

int execvpe(const char *file, char *const argv[], char *const envp[]) {
}

S void   (*old_exit)    (int status) = NULL;

void   exit    (int status) {
	xd(old_exit, exit);
	p("%s(%d)\n","exit", status);
	old_exit(status);
}

S int    (*old_fchdir)   (int fildes) = NULL;

int    fchdir   (int fildes) {
	xd(old_fchdir, fchdir);
	int tmp = old_fchdir(fildes);
	p("%s(%d) = %d\n","fchdir", fildes, tmp);
	return tmp;
}

S int (*old_fchmod)(int fildes, mode_t mode) = NULL;

int fchmod(int fildes, mode_t mode) {
	xd(old_fchmod, fchmod);
	int tmp = old_fchmod(fildes, mode);
	p("%s(%d, %d) = %d\n","fchmod", fildes, mode, tmp);
	return tmp;
}

S int (*old_fchown)(int fd, uid_t owner, gid_t group) = NULL;

int fchown(int fd, uid_t owner, gid_t group) {
	xd(old_fchown, fchown);
	int tmp = old_fchown(fd, owner, group);
	p("%s(%d, %d, %d) = %d\n","fchown", fd, owner, group, tmp);
	return tmp;
}

S DIR* (*old_fdopendir)(int fd) = NULL;

DIR* fdopendir(int fd) {
	xd(old_fdopendir, fdopendir);
	DIR* tmp = old_fdopendir(fd);
	p("%s(%d) = %p\n","fdopendir",fd, tmp);
	return tmp;
}

S pid_t (*old_fork)(void) = NULL;

pid_t fork(void) {
	xd(old_fork, fork);
	pid_t tmp = old_fork();
	p("%s() = %d\n","fork", tmp);
	return tmp;
}

S int (*old_fstat)(int fd, struct stat *buf) = NULL;

int fstat(int fd, struct stat *buf) {
	xd(old_fstat, fstat);
	int tmp = old_fstat( fd, buf);
	p("%s(%d, %p) = %d\n","fstat", fd, buf, tmp);
	return tmp;
}

S int (*old_fsync)(int fd) = NULL;

int fsync(int fd) {
	xd(old_fsync, fsync);
	int tmp = old_fsync(fd);
	p("%s(%d) = %d\n","fsync", fd, tmp);
	return tmp;
}

S int (*old_ftruncate)(int fd, off_t length) = NULL;

int ftruncate(int fd, off_t length) {
	xd(old_ftruncate,ftruncate);
	int tmp = old_ftruncate(fd, length);
	p("%s(%d, %d)\n","ftruncate", fd, length, tmp);
	return tmp;
}

S char *(*old_getcwd)(char *buf, size_t size) = NULL;

char *getcwd(char *buf, size_t size) {
	xd(old_getcwd,getcwd);
	char* tmp = old_getcwd(buf, size);
	p("%s(%s, %d) = %s\n","getcwd", buf, size, tmp);
	return tmp;
}

S gid_t (*old_getegid)(void) = NULL;

gid_t getegid(void) {
	xd(old_getegid,getegid);
	gid_t tmp = old_getegid();
	p("%s() = %d\n","getegid", tmp);
	return tmp;
}

S char* (*old_getenv) (const char* name) = NULL;

__attribute__((constructor))
void start() {
	xd(old_getenv, getenv);
	char *p = old_getenv("MONITOR_OUTPUT");
	printf("%s!!!!\n", p);

}

char* getenv(const char* name) {
	xd(old_getenv,getenv);
	char* tmp = old_getenv(name);
	p("%s(\'%s\') = \'%s\'\n", "getenv", name, tmp );
	return tmp;
}

S uid_t (*old_geteuid)(void) = NULL;

uid_t geteuid(void) {
	xd(old_geteuid, geteuid);
	uid_t tmp = old_geteuid();
	p("%s() = %d\n","geteuid", tmp);
	return tmp;
}

S gid_t (*old_getgid)(void) = NULL;

gid_t getgid(void) {
	xd(old_getgid, getgid);
	gid_t tmp = old_getgid();
	p("%s() = %d\n","getgid",tmp);
	return tmp;
}

S uid_t (*old_getuid)(void) = NULL;

uid_t getuid() {
	xd(old_getuid,getuid);
	uid_t tmp = old_getuid();
	p("%s() = %d\n", tmp );
	return tmp;
}

S int (*old_link)(const char *path1, const char *path2) = NULL;

int link(const char *path1, const char *path2) {
	xd(old_link, link);
	int tmp = old_link(path1, path2);
	p("%s(%s, %s) = %d\n","link", path1, path2, tmp);
	return tmp;
}

S int (*old_lstat)(const char *path, struct stat *buf) = NULL;

int lstat(const char *path, struct stat *buf){
	xd(old_lstat, lstat);
	int tmp = old_lstat(path, buf);
	p("%s(%s, %p) = %d\n","lstat", path, buf, tmp);
	return tmp;
}

S int (*old_mkdir)(const char *path, mode_t mode) = NULL;

int mkdir(const char *path, mode_t mode) {
	xd(old_mkdir, mkdir);
	int tmp = old_mkdir(path, mode);
	p("%s(%s, %d) = %d\n","mkdir", path, mode, tmp);
	return tmp;
}

S char *(*old_mkdtemp)(char *template) = NULL;

char *mkdtemp(char *template) {
	xd(old_mkdtemp, mkdtemp);
	char* tmp = old_mkdtemp(template);
	p("%s(%s) = %s\n","mkdtemp", template, tmp);
	return tmp;
}

S int (*old_mkfifo)(const char *path, mode_t mode) = NULL;

int mkfifo(const char *path, mode_t mode) {
	xd(old_mkfifo, mkfifo);
	int tmp = old_mkfifo(path, mode);
	p("%s(%s, %d) = %d\n","mkfifo",path, mode, tmp);
	return tmp;
}

S int (*old_mkstemp)(char *template) = NULL;

int mkstemp(char *template) {
	xd(old_mkstemp, mkstemp);
	int tmp = old_mkstemp(template);
	p("%s(%s) = %d\n","mkstemp", template, tmp);
	return tmp;
}

S int (*old_open)(const char *pathname, int flags) = NULL;
//S int (*old_open)(const char *path, int oflag, ... ) = NULL;

int open(const char* pathname, int flg) {
	xd(old_open,open);
	int tmp = old_open(pathname,flg);
	p("%s('%s' %x) = %d\n","open", pathname, flg, tmp );
	return tmp;
}

S DIR * (*old_opendir)(const char *dirname) = NULL;

DIR * opendir(const char *dirname) {
	xd(old_opendir,opendir);
	DIR *tmp = old_opendir(dirname);
	p("%s('%s') = %p\n", "opendir", dirname, tmp );
	return tmp;
}

S int (*old_pipe)(int pipefd[2]) = NULL;

int pipe(int pipefd[2]) {
	xd(old_pipe, pipe);
	int tmp = old_pipe(pipefd);
	p("%s(%p) = %d\n","pipe", pipefd, tmp);
	return tmp;
}

S ssize_t (*old_pread)(int fd, void *buf, size_t count, off_t offset) = NULL;

ssize_t pread(int fd, void *buf, size_t count, off_t offset) {
	xd(old_pread, pread);
	ssize_t tmp = old_pread(fd, buf, count, offset);
	p("%s(%d, %p, %d, %d) = %d\n","pread", fd, buf, count, offset, tmp);
	return tmp;
}

S int (*old_putenv)(char *string) = NULL;

int putenv(char *string) {
	xd(old_putenv, putenv);
	int tmp = old_putenv(string);
	p("%s(%s) = %d\n","putenv", string, tmp);
	return tmp;
}

S ssize_t (*old_pwrite)(int fd, const void *buf, size_t count, off_t offset) = NULL;

ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset) {
	xd(old_pwrite, pwrite);
	ssize_t tmp = old_pwrite(fd, buf, count, offset);
	p("%s(%d, %p, %d, %d) = %d\n","pwrite",fd, buf, count, offset, tmp);
	return tmp;
}

S int (*old_rand) (void) = NULL;

int rand (void) {
	xd(old_rand, rand);
	int tmp = old_rand();
	p("%s() = %d\n","rand", tmp);
	return tmp;
}

S int (*old_rand_r)(unsigned int *seedp) = NULL;

int rand_r(unsigned int *seedp) {
	xd(old_rand_r,rand_r);
	unsigned int tmp = old_rand_r(seedp);
	p("%s(%u) = %d\n","rand_r", seedp, tmp);
	return tmp;
}

S ssize_t (*old_read)(int fildes, void *buf, size_t nbyte) = NULL;

ssize_t read(int fildes, void *buf, size_t nbyte) {
	xd(old_read, read);
	ssize_t tmp = old_read(fildes, buf, nbyte);
	p("%s(%d, %p, %d) = %d\n","read", fildes, buf, nbyte, tmp);
	return tmp;
}

S struct dirent * (*old_readdir)(DIR * dir) = NULL;

struct dirent * readdir(DIR * dir) {
	xd(old_readdir,readdir);
	struct dirent *tmp = old_readdir(dir);
	p("%s(%p) = %p\n", "readdir", dir, tmp );
	return tmp;
}

S int (*old_readdir_r)(DIR *dirp, struct dirent *entry, struct dirent **result) = NULL;

int readdir_r(DIR *dirp, struct dirent *entry, struct dirent **result) {
	xd(old_readdir_r, readdir_r);
	int tmp = old_readdir_r(dirp, entry, result);
	p("%s(%p, %p, %p) = %d\n","readdir_r", dirp, entry, result);
	return tmp;
}

S ssize_t (*old_readlink)(const char *pathname, char *buf, size_t bufsiz) = NULL;

ssize_t readlink(const char *pathname, char *buf, size_t bufsiz) {
	xd(old_readlink, readlink);
	ssize_t tmp = old_readlink(pathname, buf, bufsiz);
	p("%s(%s, %s, %d) = %d\n","readlink", pathname, buf, bufsiz, tmp);
	return tmp;
}

S int (*old_remove) ( const char * filename ) = NULL;

int remove ( const char * filename ) {
	xd(old_remove,remove);
	int tmp = old_remove(filename);
	p("%s(%s) = %d\n","remove", filename, tmp);
	return tmp;
}

S int (*old_rename) ( const char * oldname, const char * newname ) = NULL;

int rename ( const char * oldname, const char * newname ) {
	xd(old_rename,rename);
	int tmp = old_rename( oldname, newname);
	p("%s(%s, %s) = %d\n","rename", oldname, newname, tmp);
	return tmp;
}

S void (*old_rewinddir)(DIR *dirp) = NULL;

void rewinddir(DIR *dirp) {
	xd(old_rewinddir,rewinddir);
	p("%s(%p)\n","rewinddir", dirp);
	old_rewinddir(dirp);
}

S int (*old_rmdir)(const char *path) = NULL;

int rmdir(const char *path) {
	xd(old_rmdir,rmdir);
	int tmp = old_rmdir(path);
	p("%s(%s) = %d\n","rmdir", path, tmp);
	return tmp;
}

S void (*old_seekdir)(DIR *dirp, long loc) = NULL;

void seekdir(DIR *dirp, long loc) {
	xd(old_seekdir,seekdir);
	p("%s(%p, %ld)\n","seekdir", dirp, loc);
	old_seekdir(dirp, loc);
}

S void (*old_setbuf)(FILE *stream, char *buffer) = NULL;

void setbuf(FILE *stream, char *buffer) {
	xd(old_setbuf, setbuf);
	p("%s(%p, %s)\n","setbuf", stream, buffer);
	old_setbuf(stream, buffer);
}

S int (*old_setegid)(gid_t egid) = NULL;

int setegid(gid_t egid) {
	xd(old_setegid, setegid);
	int tmp = old_setegid(egid);
	p("%s(%d) = %d\n","setegid", egid, tmp);
	return tmp;
}

S int (*old_setenv)(const char *name, const char *value, int overwrite) = NULL;

int setenv(const char *name, const char *value, int overwrite) {
	xd(old_setenv,setenv);
	int tmp = old_setenv(name,value,overwrite);
	p("%s(%s, %s, %d) = %d\n","setenv",name, value, overwrite, tmp);
	return tmp;
}

S int (*old_seteuid)(uid_t euid) = NULL;

int seteuid(uid_t euid) {
	xd(old_seteuid,seteuid);
	int tmp = old_seteuid(euid);
	p("%s(%d) = %d\n","seteuid", euid, tmp);
	return tmp;
}

S int (*old_setgid)(gid_t gid) = NULL;

int setgid(gid_t gid) {
	xd(old_setgid, setgid);
	int tmp = old_setgid(gid);
	p("%s(%d) = %d\n","setgid",gid,tmp);
	return tmp;
}

S int (*old_setuid)(uid_t uid) = NULL;

int setuid(uid_t uid) {
	xd(old_setuid, setuid);
	int tmp = old_setuid(uid);
	p("%s(%d) = %d\n","setuid",uid,tmp);
	return tmp;
}

S int (*old_setvbuf) ( FILE * stream, char * buffer, int mode, size_t size ) = NULL;

int setvbuf ( FILE * stream, char * buffer, int mode, size_t size ) {
	xd(old_setvbuf,setvbuf);
	int tmp = old_setvbuf(stream, buffer, mode, size);
	p("%s(%p, %s, %d, %d) = %d\n","setvbuf",stream,buffer,mode,size);
	return tmp;
}

S unsigned int (*old_sleep)(unsigned int seconds) = NULL;

unsigned int sleep(unsigned int seconds) {
	xd(old_sleep,sleep);
	unsigned int tmp = old_sleep(seconds);
	p("%s(%u) = %u\n","sleep",seconds,tmp);
	return tmp;
}

S void (*old_srand) (unsigned int seed) = NULL;

void srand (unsigned int seed) {
	xd(old_srand,srand);	
	p("%s(%u)\n","srand",seed);
	old_srand(seed);
}

S int (*old_stat)(const char * file_name, struct stat *buf) = NULL;

int stat(const char * file_name, struct stat *buf) {
	xd(old_stat,stat);
	int tmp = old_stat(file_name, buf);
	p("%s(%s, %p) = %d\n","stat", file_name, buf, tmp);
	return tmp;
}

S int (*old_symlink)(const char *path1, const char *path2) = NULL;

int symlink(const char *path1, const char *path2) {
	xd(old_symlink,symlink);
	int tmp = old_symlink(path1,path2);
	p("%s(%s,%s) = %d\n","symlink", path1, path2, tmp);
	return tmp;
}

S int (*old_system)(const char *command) = NULL;

int system(const char *command) {
	xd(old_system, system);
	int tmp = old_system(command);
	p("%s(%s) = %d\n","system",command, tmp);
	return tmp;
}

S long (*old_telldir)(DIR *dirp) = NULL;

long telldir(DIR *dirp) {
	xd(old_telldir, telldir);
	long tmp = old_telldir(dirp);
	p("%s(%p) = %ld\n","telldir",dirp,tmp);
	return tmp;
}

S char * (*old_tempnam)(const char *dir, const char *pfx) = NULL;

char * tempnam(const char *dir, const char *pfx) {
	xd(old_tempnam, tempnam);
	char *tmp = old_tempnam(dir,pfx);
	p("%s(%s, %s) = %s\n", "tempnam", dir, pfx, tmp);
	return tmp;
}

S FILE * (*old_tmpfile)(void) = NULL;

FILE * tmpfile(void) {
	xd(old_tmpfile,tmpfile);
	FILE *tmp = old_tmpfile();
	p("%s() = %p\n","tmpfile",tmp);
	return tmp;
}

S char * (*old_tmpnam)(char *s) = NULL;

char * tmpnam(char *s){
	xd(old_tmpnam,tmpnam);
	char *tmp = old_tmpnam(s);
	p("%s(%s) = %s\n","tmpnam", s, tmp );
	return tmp;
}

S mode_t (*old_umask)(mode_t mask) = NULL;

mode_t umask(mode_t mask){
	xd(old_umask,umask);
	mode_t tmp = umask(mask);
	p("%s(%d) = %d\n", "umask",mask, tmp);
	return tmp;
}

S int (*old_unlinkat)(int dirfd, const char *pathname, int flags) = NULL;

int unlinkat(int dirfd, const char *pathname, int flags){
	xd(old_unlinkat,unlinkat);
	int tmp = old_unlinkat(dirfd, pathname, flags);
	p("%s(%d, %s, %d) = %d\n", "unlinkat", dirfd, pathname, flags, tmp);
	return tmp;
}

S ssize_t (*old_write)(int fd, const void *buf, size_t count) = NULL;

ssize_t write(int fd, const void *buf, size_t count) {
	xd(old_write,write);
	ssize_t tmp = old_write(fd,buf,count);
	p("%s(%d, %p, %d) = %d\n","write",fd,buf,count, tmp );
	return tmp;
}
