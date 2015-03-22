// Fake a few definitions that mk20dx128.[ch] expects
#ifndef __MK20DX128_COMPAT_H__
#define __MK20DX128_COMPAT_H__

#define S_IFCHR    0020000
#include <inttypes.h>

typedef uint32_t dev_t;
typedef uint32_t ino_t;
typedef uint32_t mode_t;
typedef uint32_t nlink_t;
typedef uint32_t uid_t;
typedef uint32_t gid_t;
typedef uint32_t off_t;
typedef uint32_t blksize_t;
typedef uint32_t blkcnt_t;
typedef uint32_t time_t;

struct stat {
  dev_t st_dev;         /* ID of device containing file */
  ino_t st_ino;         /* inode number */
  mode_t st_mode;       /* protection */
  nlink_t st_nlink;     /* number of hard links */
  uid_t st_uid;         /* user ID of owner */
  gid_t st_gid;         /* group ID of owner */
  dev_t st_rdev;        /* device ID (if special file) */
  off_t st_size;        /* total size, in bytes */
  blksize_t st_blksize; /* blocksize for file system I/O */
  blkcnt_t st_blocks;   /* number of 512B blocks allocated */
  time_t st_atime;      /* time of last access */
  time_t st_mtime;      /* time of last modification */
  time_t st_ctime;      /* time of last status change */
};

#undef dev_t
#undef ino_t
#undef mode_t
#undef nlink_t
#undef uid_t
#undef gid_t
#undef off_t
#undef blksize_t
#undef blkcnt_t
#undef time_t

#endif // __MK20DX128_COMPAT_H__
