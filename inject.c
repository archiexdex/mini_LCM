#include <dlfcn.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define S static
#define mo "[monitor]"
#define dl dlopen("libc.so.6", RTLD_LAZY)
#define xd(a,b)({if(!a){void *ptr=dl; if(ptr) a=dlsym(ptr,#b);}})
#define p(a,...) { fprintf(stderr,"[monitor] "); fprintf(stderr,#a,__VA_ARGS__); } 

S void (*old__exit)(int status) = NULL;

void _exit(int status) {
	xd(old__exit,_exit);
	p(%s(%d)\n, "_exit", status);
	old__exit(status);
}
S int (*old_chdir)(const char *path) = NULL;

int chdir(const char *path){
	xd(old_chdir,chdir);
	int tmp = old_chdir(path);
	p(%s('%s') = %d\n,"chdir", path, tmp );
	return tmp;
}

S int (*old_chmod)(const char *pathname, mode_t mode) = NULL;

int chmod(const char *pathname, mode_t mode) {
	xd(old_chmod,chmod);
	int tmp = old_chmod(pathname, mode);
	p(%s(%s, %d) = %d\n, "chmod",pathname, mode, tmp );
	return tmp;
}

S int (*old_chown)(const char *pathname, uid_t owner, gid_t group) = NULL;

int chown(const char *pathname, uid_t owner, gid_t group) {
	
}

S int (*old_close)(int fd) = NULL;

int close(int fd){

}

S int (*old_closedir)(DIR *dirp) = NULL;

int closedir(DIR *dirp){

}

S int (*old_creat)(const char *path, mode_t mode) = NULL;

int creat(const char *path, mode_t mode){

}

S int (*old_dup)(int oldfd) = NULL;

int dup(int oldfd) {
}

S int (*old_dup2)(int oldfd, int newfd) = NULL;

int  dup2(int oldfd, int newfd) {
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
}

S int    (*old_fchdir)   (int fildes) = NULL;

int    fchdir   (int fildes) {
}

S int (*old_fchmod)(int fildes, mode_t mode) = NULL;

int fchmod(int fildes, mode_t mode) {
}

S int (*old_fchown)(int fd, uid_t owner, gid_t group) = NULL;

int fchown(int fd, uid_t owner, gid_t group) {
}

S DIR* (*old_fdopendir)(int fd) = NULL;

DIR* fdopendir(int fd) {
}

S pid_t (*old_fork)(void) = NULL;

pid_t fork(void) {
}

S int (*old_fstat)(int fd, struct stat *buf) = NULL;

int fstat(int fd, struct stat *buf) {
}

S int (*old_fsync)(int fd) = NULL;

int fsync(int fd) {
}

S int (*old_ftruncate)(int fd, off_t length) = NULL;

int ftruncate(int fd, off_t length) {
}

S char *(*old_getcwd)(char *buf, size_t size) = NULL;

char *getcwd(char *buf, size_t size) {

}

S gid_t (*old_getegid)(void) = NULL;

gid_t getegid(void) {
}

S char* (*old_getenv) (const char* name) = NULL;

char* getenv(const char* name) {
	xd(old_getenv,getenv);
	char* tmp = old_getenv(name);
	printf("%s %s(\'%s\') = \'%s\'\n", mo, "getenv", name, tmp );
	return tmp;
}

S uid_t (*old_geteuid)(void) = NULL;

uid_t geteuid(void) {
}

S gid_t (*old_getgid)(void) = NULL;

gid_t getgid(void) {
}

S uid_t (*old_getuid)(void) = NULL;

uid_t getuid() {
	if( !old_getuid ) {
		void *ptr = dl; 
		if ( ptr )
			old_getuid = dlsym(ptr, "getuid");
	}
	fprintf(stderr, "getuid() = %d\n", old_getuid() );
	
	return old_getuid();
}

S int (*old_link)(const char *path1, const char *path2) = NULL;

int link(const char *path1, const char *path2) {
}

S int (*old_lstat)(const char *path, struct stat *buf) = NULL;

int lstat(const char *path, struct stat *buf){
}

S int (*old_mkdir)(const char *path, mode_t mode) = NULL;

int mkdir(const char *path, mode_t mode) {
}

S char *(*old_mkdtemp)(char *template) = NULL;

char *mkdtemp(char *template) {
}

S int (*old_mkfifo)(const char *path, mode_t mode) = NULL;

int mkfifo(const char *path, mode_t mode) {
}

S int (*old_mkstemp)(char *template) = NULL;

int mkstemp(char *template) {
}

S int (*old_open)(const char *pathname, int flags) = NULL;
//S int (*old_open)(const char *path, int oflag, ... ) = NULL;

int open(const char* pathname, int flg) {
	if ( !old_open ){
		void *ptr = dlopen("libc.so.6", RTLD_LAZY);
		if ( ptr )
			old_open = dlsym(ptr, "open");
	}
	fprintf(stderr,"%s %s(\'%s\' %x) = %d\n",mo, "open", pathname, flg, old_open(pathname, flg) );
	return old_open(pathname, flg);
}

S DIR * (*old_opendir)(const char *dirname) = NULL;

DIR * opendir(const char *dirname) {
	xd(old_opendir,opendir);
	DIR *tmp = old_opendir(dirname);
	fprintf(stderr, "%s %s('%s') = %p\n",mo, "opendir", dirname, tmp );
	return tmp;
}

S int (*old_pipe)(int pipefd[2]) = NULL;

int pipe(int pipefd[2]) {
}

S ssize_t (*old_pread)(int fd, void *buf, size_t count, off_t offset) = NULL;

ssize_t pread(int fd, void *buf, size_t count, off_t offset) {
}

S int (*old_putenv)(char *string) = NULL;

int putenv(char *string) {
}

S ssize_t (*old_pwrite)(int fd, const void *buf, size_t count, off_t offset) = NULL;

ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset) {
}

S int (*old_rand) (void) = NULL;

int rand (void) {
}

S int (*old_rand_r)(unsigned int *seedp) = NULL;

int rand_r(unsigned int *seedp) {
}

S ssize_t (*old_read)(int fildes, void *buf, size_t nbyte) = NULL;

ssize_t read(int fildes, void *buf, size_t nbyte) {
}

S struct dirent * (*old_readdir)(DIR * dir) = NULL;

struct dirent * readdir(DIR * dir) {
	xd(old_readdir,readdir);
	struct dirent *tmp = old_readdir(dir);
	fprintf(stderr,"%s %s(%p) = %p\n",mo, "readdir", dir, tmp );
	return tmp;
}

S int (*old_readdir_r)(DIR *dirp, struct dirent *entry, struct dirent **result) = NULL;

int readdir_r(DIR *dirp, struct dirent *entry, struct dirent **result) {
}

S ssize_t (*old_readlink)(const char *pathname, char *buf, size_t bufsiz) = NULL;

ssize_t readlink(const char *pathname, char *buf, size_t bufsiz) {
}

S int (*old_remove) ( const char * filename ) = NULL;

int remove ( const char * filename ) {
}

S int (*old_rename) ( const char * oldname, const char * newname ) = NULL;

int rename ( const char * oldname, const char * newname ) {
}

S void (*old_rewinddir)(DIR *dirp) = NULL;

void rewinddir(DIR *dirp) {
}

S int (*old_rmdir)(const char *path) = NULL;

int rmdir(const char *path) {
}

S void (*old_seekdir)(DIR *dirp, long loc) = NULL;

void seekdir(DIR *dirp, long loc) {
}

S void (*old_setbuf)(FILE *stream, char *buffer) = NULL;

void setbuf(FILE *stream, char *buffer) {
}

S int (*old_setegid)(gid_t egid) = NULL;

int setegid(gid_t egid) {
}

S int (*old_setenv)(const char *name, const char *value, int overwrite) = NULL;

int setenv(const char *name, const char *value, int overwrite) {
}

S int (*old_seteuid)(uid_t euid) = NULL;

int seteuid(uid_t euid) {
}

S int (*old_setgid)(gid_t gid) = NULL;

int setgid(gid_t gid) {
}

S int (*old_setuid)(uid_t uid) = NULL;

int setuid(uid_t uid) {
}
S int (*old_setvbuf) ( FILE * stream, char * buffer, int mode, size_t size ) = NULL;

int setvbuf ( FILE * stream, char * buffer, int mode, size_t size ) {
}

S unsigned int (*old_sleep)(unsigned int seconds) = NULL;

unsigned int sleep(unsigned int seconds) {
}

S void (*old_srand) (unsigned int seed) = NULL;

void srand (unsigned int seed) {
}

S int (*old_stat)(const char * file_name, struct stat *buf) = NULL;

int stat(const char * file_name, struct stat *buf) {
}

S int (*old_symlink)(const char *path1, const char *path2) = NULL;

int symlink(const char *path1, const char *path2) {
}

S int (*old_system)(const char *command) = NULL;

int system(const char *command) {
}

S long (*old_telldir)(DIR *dirp) = NULL;

long telldir(DIR *dirp) {
}

S char * (*old_tempnam)(const char *dir, const char *pfx) = NULL;

char * tempnam(const char *dir, const char *pfx) {
	xd(old_tempnam, tempnam);
	char *tmp = old_tempnam(dir,pfx);
	p(%s(%s, %s) = %s\n, "tempnam", dir, pfx, tmp);
	return tmp;
}

S FILE * (*old_tmpfile)(void) = NULL;

FILE * tmpfile(void) {
	xd(old_tmpfile,tmpfile);
	FILE *tmp = old_tmpfile();
	p(%s() = %p\n,"tmpfile",tmp);
	return tmp;
}

S char * (*old_tmpnam)(char *s) = NULL;

char * tmpnam(char *s){
	xd(old_tmpnam,tmpnam);
	char *tmp = old_tmpnam(s);
	p(%s(%s) = %s\n,"tmpnam", s, tmp );
	return tmp;
}

S mode_t (*old_umask)(mode_t mask) = NULL;

mode_t umask(mode_t mask){
	xd(old_umask,umask);
	mode_t tmp = umask(mask);
	p(%s(%d) = %d\n, "umask",mask, tmp);
	return tmp;
}

S int (*old_unlinkat)(int dirfd, const char *pathname, int flags) = NULL;

int unlinkat(int dirfd, const char *pathname, int flags){
	xd(old_unlinkat,unlinkat);
	int tmp = old_unlinkat(dirfd, pathname, flags);
	p(%s(%d, %s, %d) = %d\n, "unlinkat", dirfd, pathname, flags, tmp);
	return tmp;
}

S ssize_t (*old_write)(int fd, const void *buf, size_t count) = NULL;

ssize_t write(int fd, const void *buf, size_t count) {
	xd(old_write,write);
	ssize_t tmp = old_write(fd,buf,count);
	p(%s(%d, %p, %d) = %d\n,"write",fd,buf,count, tmp );
	return tmp;
}
