#ifndef _S21_APPLE_ERRLIST_H_
#define _S21_APPLE_ERRLIST_H_
    S21_S(0, "Undefined error: 0")
    #ifdef EPERM
    S21_S(EPERM, "Operation not permitted")
    #endif
    #ifdef ENOENT
    S21_S(ENOENT, "No such file or directory")
    #endif
    #ifdef ESRCH
    S21_S(ESRCH, "No such process")
    #endif
    #ifdef EINTR
    S21_S(EINTR, "Interrupted system call")
    #endif
    #ifdef EIO
    S21_S(EIO, "Input/output error")
    #endif
    #ifdef ENXIO
    S21_S(ENXIO, "Device not configured")
    #endif
    #ifdef ENOEXEC
    S21_S(ENOEXEC, "Exec format error")
    #endif
    #ifdef EBADF
    S21_S(EBADF, "Bad file descriptor")
    #endif
    #ifdef ECHILD
    S21_S(ECHILD, "No child processes")
    #endif
    #ifdef EDEADLK
    S21_S(EDEADLK, "Resource deadlock avoided")
    #endif
    #ifdef ENOMEM
    S21_S(ENOMEM, "Cannot allocate memory")
    #endif
    #ifdef EACCES
    S21_S(EACCES, "Permission denied")
    #endif
    #ifdef EFAULT
    S21_S(EFAULT, "Bad address")
    #endif
    #ifdef ENOTBLK
    S21_S(ENOTBLK, "Block device required")
    #endif
    #ifdef EBUSY
    S21_S(EBUSY, "Resource busy")
    #endif
    #ifdef EEXIST
    S21_S(EEXIST, "File exists")
    #endif
    #ifdef EXDEV
    S21_S(EXDEV, "Cross-device link")
    #endif
    #ifdef ENODEV
    S21_S(ENODEV, "Operation not supported by device")
    #endif
    #ifdef ENOTDIR
    S21_S(ENOTDIR, "Not a directory")
    #endif
    #ifdef EISDIR
    S21_S(EISDIR, "Is a directory")
    #endif
    #ifdef EINVAL
    S21_S(EINVAL, "Invalid argument")
    #endif
    #ifdef ENFILE
    S21_S(ENFILE, "Too many open files in system")
    #endif
    #ifdef EMFILE
    S21_S(EMFILE, "Too many open files")
    #endif
    #ifdef ENOTTY
    S21_S(ENOTTY, "Inappropriate ioctl for device")
    #endif
    #ifdef ETXTBSY
    S21_S(ETXTBSY, "Text file busy")
    #endif
    #ifdef EFBIG
    S21_S(EFBIG, "File too large")
    #endif
    #ifdef ENOSPC
    S21_S(ENOSPC, "No space left on device")
    #endif
    #ifdef ESPIPE
    S21_S(ESPIPE, "Illegal seek")
    #endif
    #ifdef EROFS
    S21_S(EROFS, "Read-only file system")
    #endif
    #ifdef EMLINK
    S21_S(EMLINK, "Too many links")
    #endif
    #ifdef EPIPE
    S21_S(EPIPE, "Broken pipe")
    #endif
    #ifdef EDOM
    S21_S(EDOM, "Numerical argument out of domain")
    #endif
    #ifdef ERANGE
    S21_S(ERANGE, "Result too large")
    #endif
    #ifdef EAGAIN
    S21_S(EAGAIN, "Resource temporarily unavailable")
    #endif
    #ifdef EINPROGRESS
    S21_S(EINPROGRESS, "Operation now in progress")
    #endif
    #ifdef EALREADY
    S21_S(EALREADY, "Operation already in progress")
    #endif
    #ifdef ENOTSOCK
    S21_S(ENOTSOCK, "Socket operation on non-socket")
    #endif
    #ifdef EDESTADDRREQ
    S21_S(EDESTADDRREQ, "Destination address required")
    #endif
    #ifdef EMSGSIZE
    S21_S(EMSGSIZE, "Message too long")
    #endif
    #ifdef EPROTOTYPE
    S21_S(EPROTOTYPE, "Protocol wrong type for socket")
    #endif
    #ifdef ENOPROTOOPT
    S21_S(ENOPROTOOPT, "Protocol not available")
    #endif
    #ifdef EPROTONOSUPPORT
    S21_S(EPROTONOSUPPORT, "Protocol not supported")
    #endif
    #ifdef ESOCKTNOSUPPORT
    S21_S(ESOCKTNOSUPPORT, "Socket type not supported")
    #endif
    #ifdef ENOTSUP
    S21_S(ENOTSUP, "Operation not supported")
    #endif
    #ifdef EPFNOSUPPORT
    S21_S(EPFNOSUPPORT, "Protocol family not supported")
    #endif
    #ifdef EADDRINUSE
    S21_S(EADDRINUSE, "Address already in use")
    #endif
    #ifdef EADDRNOTAVAIL
    S21_S(EADDRNOTAVAIL, "Can't assign requested address")
    #endif
    #ifdef ENETDOWN
    S21_S(ENETDOWN, "Network is down")
    #endif
    #ifdef ENETUNREACH
    S21_S(ENETUNREACH, "Network is unreachable")
    #endif
    #ifdef ENETRESET
    S21_S(ENETRESET, "Network dropped connection on reset")
    #endif
    #ifdef ECONNABORTED
    S21_S(ECONNABORTED, "Software caused connection abort")
    #endif
    #ifdef ECONNRESET
    S21_S(ECONNRESET, "Connection reset by peer")
    #endif
    #ifdef ENOBUFS
    S21_S(ENOBUFS, "No buffer space available")
    #endif
    #ifdef EISCONN
    S21_S(EISCONN, "Socket is already connected")
    #endif
    #ifdef ENOTCONN
    S21_S(ENOTCONN, "Socket is not connected")
    #endif
    #ifdef ESHUTDOWN
    S21_S(ESHUTDOWN, "Can't send after socket shutdown")
    #endif
    #ifdef ETOOMANYREFS
    S21_S(ETOOMANYREFS, "Too many references: can't splice")
    #endif
    #ifdef ETIMEDOUT
    S21_S(ETIMEDOUT, "Operation timed out")
    #endif
    #ifdef ECONNREFUSED
    S21_S(ECONNREFUSED, "Connection refused")
    #endif
    #ifdef ELOOP
    S21_S(ELOOP, "Too many levels of symbolic links")
    #endif
    #ifdef ENAMETOOLONG
    S21_S(ENAMETOOLONG, "File name too long")
    #endif
    #ifdef EHOSTDOWN
    S21_S(EHOSTDOWN, "Host is down")
    #endif
    #ifdef EHOSTUNREACH
    S21_S(EHOSTUNREACH, "No route to host")
    #endif
    #ifdef ENOTEMPTY
    S21_S(ENOTEMPTY, "Directory not empty")
    #endif
    #ifdef EPROCLIM
    S21_S(EPROCLIM, "Too many processes")
    #endif
    #ifdef EUSERS
    S21_S(EUSERS, "Too many users")
    #endif
    #ifdef EDQUOT
    S21_S(EDQUOT, "Disc quota exceeded")
    #endif
    #ifdef ESTALE
    S21_S(ESTALE, "Stale NFS file handle")
    #endif
    #ifdef EREMOTE
    S21_S(EREMOTE, "Too many levels of remote in path")
    #endif
    #ifdef EBADRPC
    S21_S(EBADRPC, "RPC struct is bad")
    #endif
    #ifdef ERPCMISMATCH
    S21_S(ERPCMISMATCH, "RPC version wrong")
    #endif
    #ifdef EPROGUNAVAIL
    S21_S(EPROGUNAVAIL, "RPC prog. not avail")
    #endif
    #ifdef EPROGMISMATCH
    S21_S(EPROGMISMATCH, "Program version wrong")
    #endif
    #ifdef EPROCUNAVAIL
    S21_S(EPROCUNAVAIL, "Bad procedure for program")
    #endif
    #ifdef ENOLCK
    S21_S(ENOLCK, "No locks available")
    #endif
    #ifdef ENOSYS
    S21_S(ENOSYS, "Function not implemented")
    #endif
    #ifdef EFTYPE
    S21_S(EFTYPE, "Inappropriate file type or format")
    #endif
    #ifdef EAUTH
    S21_S(EAUTH, "Authentication error")
    #endif
    #ifdef ENEEDAUTH
    S21_S(ENEEDAUTH, "Need authenticator")
    #endif
    #ifdef EPWROFF
    S21_S(EPWROFF, "Device power is off")
    #endif
    #ifdef EDEVERR
    S21_S(EDEVERR, "Device error")
    #endif
    #ifdef EOVERFLOW
    S21_S(EOVERFLOW, "Value too large to be stored in data type")
    #endif
    #ifdef EBADEXEC
    S21_S(EBADEXEC, "Bad executable (or shared library)")
    #endif
    #ifdef EBADARCH
    S21_S(EBADARCH, "Bad CPU type in executable")
    #endif
    #ifdef ESHLIBVERS
    S21_S(ESHLIBVERS, "Shared library version mismatch")
    #endif
    #ifdef EBADMACHO
    S21_S(EBADMACHO, "Malformed Mach-o file")
    #endif
    #ifdef ECANCELED
    S21_S(ECANCELED, "Operation canceled")
    #endif
    #ifdef EIDRM
    S21_S(EIDRM, "Identifier removed")
    #endif
    #ifdef ENOMSG
    S21_S(ENOMSG, "No message of desired type")
    #endif
    #ifdef EILSEQ
    S21_S(EILSEQ, "Illegal byte sequence")
    #endif
    #ifdef ENOATTR
    S21_S(ENOATTR, "Attribute not found")
    #endif
    #ifdef EBADMSG
    S21_S(EBADMSG, "Bad message")
    #endif
    #ifdef EMULTIHOP
    S21_S(EMULTIHOP, "EMULTIHOP (Reserved)")
    #endif
    #ifdef ENODATA
    S21_S(ENODATA, "No message available on STREAM")
    #endif
    #ifdef ENOLINK
    S21_S(ENOLINK, "ENOLINK (Reserved)")
    #endif
    #ifdef ENOSR
    S21_S(ENOSR, "No STREAM resources")
    #endif
    #ifdef ENOSTR
    S21_S(ENOSTR, "Not a STREAM")
    #endif
    #ifdef EPROTO
    S21_S(EPROTO, "Protocol error")
    #endif
    #ifdef ETIME
    S21_S(ETIME, "STREAM ioctl timeout")
    #endif
    #ifdef EOPNOTSUPP
    S21_S(EOPNOTSUPP, "Operation not supported on socket")
    #endif
    #ifdef ENOPOLICY
    S21_S(ENOPOLICY, "Policy not found")
    #endif
    #ifdef ENOTRECOVERABLE
    S21_S(ENOTRECOVERABLE, "State not recoverable")
    #endif
    #ifdef EOWNERDEAD
    S21_S(EOWNERDEAD, "Previous owner died")
    #endif
    #ifdef EQFULL
    S21_S(EQFULL, "Interface output queue is full")
    #endif
    #ifdef ENOTCAPABLE
    S21_S(ENOTCAPABLE, "Capabilities insufficient")
    #endif
#endif  // _S21_APPLE_ERRLIST_H_