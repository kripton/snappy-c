#ifdef __FreeBSD__
#  include <sys/endian.h>
#elif defined(__APPLE_CC_) || defined(__MACH__)  /* MacOS/X support */
#  include <machine/endian.h>

#if    __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN
#  define	htole16(x) (x)
#  define	le32toh(x) (x)
#elif  __DARWIN_BYTE_ORDER == __DARWIN_BIG_ENDIAN
#  define	htole16(x) __DARWIN_OSSwapInt16(x)
#  define	le32toh(x) __DARWIN_OSSwapInt32(x)
#else
#  error "Endianness is undefined"
#endif


#elif !defined(__WIN32__)
#  include <machine/endian.h>
#endif

static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}

static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}

static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}


# if __BYTE_ORDER == __LITTLE_ENDIAN
#  define htobe16(x) __bswap_16 (x)
#  define htole16(x) __uint16_identity (x)
#  define be16toh(x) __bswap_16 (x)
#  define le16toh(x) __uint16_identity (x)

#  define htobe32(x) __bswap_32 (x)
#  define htole32(x) __uint32_identity (x)
#  define be32toh(x) __bswap_32 (x)
#  define le32toh(x) __uint32_identity (x)

#  define htobe64(x) __bswap_64 (x)
#  define htole64(x) __uint64_identity (x)
#  define be64toh(x) __bswap_64 (x)
#  define le64toh(x) __uint64_identity (x)

# else
#  define htobe16(x) __uint16_identity (x)
#  define htole16(x) __bswap_16 (x)
#  define be16toh(x) __uint16_identity (x)
#  define le16toh(x) __bswap_16 (x)

#  define htobe32(x) __uint32_identity (x)
#  define htole32(x) __bswap_32 (x)
#  define be32toh(x) __uint32_identity (x)
#  define le32toh(x) __bswap_32 (x)

#  define htobe64(x) __uint64_identity (x)
#  define htole64(x) __bswap_64 (x)
#  define be64toh(x) __uint64_identity (x)
#  define le64toh(x) __bswap_64 (x)
# endif


#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <limits.h>
#ifndef __WIN32__
//#include <sys/uio.h>
#include <sys/types.h>
#endif

#ifdef __ANDROID__
#define le32toh letoh32
#endif

#if defined(__WIN32__) && defined(SG)
struct iovec {
	void *iov_base;	/* Pointer to data.  */
	size_t iov_len;	/* Length of data.  */
};
#endif

#define get_unaligned_memcpy(x) ({ \
		typeof(*(x)) _ret; \
		memcpy(&_ret, (x), sizeof(*(x))); \
		_ret; })
#define put_unaligned_memcpy(v,x) ({ \
		typeof((v)) _v = (v); \
		memcpy((x), &_v, sizeof(*(x))); })

#define get_unaligned get_unaligned_memcpy
#define put_unaligned put_unaligned_memcpy
#define get_unaligned64 get_unaligned_memcpy
#define put_unaligned64 put_unaligned_memcpy

#define get_unaligned_le32(x) (le32toh(get_unaligned((u32 *)(x))))
#define put_unaligned_le16(v,x) (put_unaligned(htole16(v), (u16 *)(x)))

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef unsigned long long u64;

#define BUG_ON(x) assert(!(x))

#define vmalloc(x) malloc(x)
#define vfree(x) free(x)

#define EXPORT_SYMBOL(x)

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

#define min_t(t,x,y) ((x) < (y) ? (x) : (y))
#define max_t(t,x,y) ((x) > (y) ? (x) : (y))

#if __BYTE_ORDER == __LITTLE_ENDIAN
#define __LITTLE_ENDIAN__ 1
#endif

#if __LITTLE_ENDIAN__ == 1 && (defined(__LSB_VERSION__) || defined(__WIN32__))
#define htole16(x) (x)
#define le32toh(x) (x)
#endif

#define BITS_PER_LONG (__SIZEOF_LONG__ * 8)
