#ifndef _S21_LINUX_ERRLIST_H_
#define _S21_LINUX_ERRLIST_H_
    S21_S(0, "Success")
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
    S21_S(ENXIO, "No such device or address")
    #endif
    #ifdef E2BIG
    S21_S(E2BIG, "Argument list too long")
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
    S21_S(EBUSY, "Device or resource busy")
    #endif
    #ifdef EEXIST
    S21_S(EEXIST, "File exists")
    #endif
    #ifdef EXDEV
    S21_S(EXDEV, "Invalid cross-device link")
    #endif
    #ifdef ENODEV
    S21_S(ENODEV, "No such device")
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
    #ifdef EMFILE
    S21_S(EMFILE, "Too many open files")
    #endif
    #ifdef ENFILE
    S21_S(ENFILE, "Too many open files in system")
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
    S21_S(ERANGE, "Numerical result out of range")
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
    #ifdef EOPNOTSUPP
    S21_S(EOPNOTSUPP, "Operation not supported")
    #endif
    #ifdef EPFNOSUPPORT
    S21_S(EPFNOSUPPORT, "Protocol family not supported")
    #endif
    #ifdef EAFNOSUPPORT
    S21_S(EAFNOSUPPORT, "Address family not supported by protocol")
    #endif
    #ifdef EADDRINUSE
    S21_S(EADDRINUSE, "Address already in use")
    #endif
    #ifdef EADDRNOTAVAIL
    S21_S(EADDRNOTAVAIL, "Cannot assign requested address")
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
    S21_S(EISCONN, "Transport endpoint is already connected")
    #endif
    #ifdef ENOTCONN
    S21_S(ENOTCONN, "Transport endpoint is not connected")
    #endif
    #ifdef EDESTADDRREQ
    S21_S(EDESTADDRREQ, "Destination address required")
    #endif
    #ifdef ESHUTDOWN
    S21_S(ESHUTDOWN, "Cannot send after transport endpoint shutdown")
    #endif
    #ifdef ETOOMANYREFS
    S21_S(ETOOMANYREFS, "Too many references: cannot splice")
    #endif
    #ifdef ETIMEDOUT
    S21_S(ETIMEDOUT, "Connection timed out")
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
    #ifdef EUSERS
    S21_S(EUSERS, "Too many users")
    #endif
    #ifdef EDQUOT
    S21_S(EDQUOT, "Disk quota exceeded")
    #endif
    #ifdef ESTALE
    S21_S(ESTALE, "Stale file handle")
    #endif
    #ifdef EREMOTE
    S21_S(EREMOTE, "Object is remote")
    #endif
    #ifdef ENOLCK
    S21_S(ENOLCK, "No locks available")
    #endif
    #ifdef ENOSYS
    S21_S(ENOSYS, "Function not implemented")
    #endif
    #ifdef EILSEQ
    S21_S(EILSEQ, "Invalid or incomplete multibyte or wide character")
    #endif
    #ifdef EBADMSG
    S21_S(EBADMSG, "Bad message")
    #endif
    #ifdef EIDRM
    S21_S(EIDRM, "Identifier removed")
    #endif
    #ifdef EMULTIHOP
    S21_S(EMULTIHOP, "Multihop attempted")
    #endif
    #ifdef ENODATA
    S21_S(ENODATA, "No data available")
    #endif
    #ifdef ENOLINK
    S21_S(ENOLINK, "Link has been severed")
    #endif
    #ifdef ENOMSG
    S21_S(ENOMSG, "No message of desired type")
    #endif
    #ifdef ENOSR
    S21_S(ENOSR, "Out of streams resources")
    #endif
    #ifdef ENOSTR
    S21_S(ENOSTR, "Device not a stream")
    #endif
    #ifdef EOVERFLOW
    S21_S(EOVERFLOW, "Value too large for defined data type")
    #endif
    #ifdef EPROTO
    S21_S(EPROTO, "Protocol error")
    #endif
    #ifdef ETIME
    S21_S(ETIME, "Timer expired")
    #endif
    #ifdef ECANCELED
    S21_S(ECANCELED, "Operation canceled")
    #endif
    #ifdef EOWNERDEAD
    S21_S(EOWNERDEAD, "Owner died")
    #endif
    #ifdef ENOTRECOVERABLE
    S21_S(ENOTRECOVERABLE, "State not recoverable")
    #endif
    #ifdef ERESTART
    S21_S(ERESTART, "Interrupted system call should be restarted")
    #endif
    #ifdef ECHRNG
    S21_S(ECHRNG, "Channel number out of range")
    #endif
    #ifdef EL2NSYNC
    S21_S(EL2NSYNC, "Level 2 not synchronized")
    #endif
    #ifdef EL3HLT
    S21_S(EL3HLT, "Level 3 halted")
    #endif
    #ifdef EL3RST
    S21_S(EL3RST, "Level 3 reset")
    #endif
    #ifdef ELNRNG
    S21_S(ELNRNG, "Link number out of range")
    #endif
    #ifdef EUNATCH
    S21_S(EUNATCH, "Protocol driver not attached")
    #endif
    #ifdef ENOCSI
    S21_S(ENOCSI, "No CSI structure available")
    #endif
    #ifdef EL2HLT
    S21_S(EL2HLT, "Level 2 halted")
    #endif
    #ifdef EBADE
    S21_S(EBADE, "Invalid exchange")
    #endif
    #ifdef EBADR
    S21_S(EBADR, "Invalid request descriptor")
    #endif
    #ifdef EXFULL
    S21_S(EXFULL, "Exchange full")
    #endif
    #ifdef ENOANO
    S21_S(ENOANO, "No anode")
    #endif
    #ifdef EBADRQC
    S21_S(EBADRQC, "Invalid request code")
    #endif
    #ifdef EBADSLT
    S21_S(EBADSLT, "Invalid slot")
    #endif
    #if defined EDEADLOCK && EDEADLOCK != EDEADLK
    S21_S (EDEADLOCK, "File locking deadlock error")
    #endif
    #ifdef EBFONT
    S21_S(EBFONT, "Bad font file format")
    #endif
    #ifdef ENONET
    S21_S(ENONET, "Machine is not on the network")
    #endif
    #ifdef ENOPKG
    S21_S(ENOPKG, "Package not installed")
    #endif
    #ifdef EADV
    S21_S(EADV, "Advertise error")
    #endif
    #ifdef ESRMNT
    S21_S(ESRMNT, "Srmount error")
    #endif
    #ifdef ECOMM
    S21_S(ECOMM, "Communication error on send")
    #endif
    #ifdef EDOTDOT
    S21_S(EDOTDOT, "RFS specific error")
    #endif
    #ifdef ENOTUNIQ
    S21_S(ENOTUNIQ, "Name not unique on network")
    #endif
    #ifdef EBADFD
    S21_S(EBADFD, "File descriptor in bad state")
    #endif
    #ifdef EREMCHG
    S21_S(EREMCHG, "Remote address changed")
    #endif
    #ifdef ELIBACC
    S21_S(ELIBACC, "Can not access a needed shared library")
    #endif
    #ifdef ELIBBAD
    S21_S(ELIBBAD, "Accessing a corrupted shared library")
    #endif
    #ifdef ELIBSCN
    S21_S(ELIBSCN, ".lib section in a.out corrupted")
    #endif
    #ifdef ELIBMAX
    S21_S(ELIBMAX, "Attempting to link in too many shared libraries")
    #endif
    #ifdef ELIBEXEC
    S21_S(ELIBEXEC, "Cannot exec a shared library directly")
    #endif
    #ifdef ESTRPIPE
    S21_S(ESTRPIPE, "Streams pipe error")
    #endif
    #ifdef EUCLEAN
    S21_S(EUCLEAN, "Structure needs cleaning")
    #endif
    #ifdef ENOTNAM
    S21_S(ENOTNAM, "Not a XENIX named type file")
    #endif
    #ifdef ENAVAIL
    S21_S(ENAVAIL, "No XENIX semaphores available")
    #endif
    #ifdef EISNAM
    S21_S(EISNAM, "Is a named type file")
    #endif
    #ifdef EREMOTEIO
    S21_S(EREMOTEIO, "Remote I/O error")
    #endif
    #ifdef ENOMEDIUM
    S21_S(ENOMEDIUM, "No medium found")
    #endif
    #ifdef EMEDIUMTYPE
    S21_S(EMEDIUMTYPE, "Wrong medium type")
    #endif
    #ifdef ENOKEY
    S21_S(ENOKEY, "Required key not available")
    #endif
    #ifdef EKEYEXPIRED
    S21_S(EKEYEXPIRED, "Key has expired")
    #endif
    #ifdef EKEYREVOKED
    S21_S(EKEYREVOKED, "Key has been revoked")
    #endif
    #ifdef EKEYREJECTED
    S21_S(EKEYREJECTED, "Key was rejected by service")
    #endif
    #ifdef ERFKILL
    S21_S(ERFKILL, "Operation not possible due to RF-kill")
    #endif
    #ifdef EHWPOISON
    S21_S(EHWPOISON, "Memory page has hardware error")
    #endif
    #ifdef EBADRPC
    S21_S(EBADRPC, "RPC struct is bad")
    #endif
    #ifdef EFTYPE
    S21_S(EFTYPE, "Inappropriate file type or format")
    #endif
    #ifdef EPROCUNAVAIL
    S21_S(EPROCUNAVAIL, "RPC bad procedure for program")
    #endif
    #ifdef EAUTH
    S21_S(EAUTH, "Authentication error")
    #endif
    #ifdef EDIED
    S21_S(EDIED, "Translator died")
    #endif
    #ifdef ERPCMISMATCH
    S21_S(ERPCMISMATCH, "RPC version wrong")
    #endif
    #ifdef EGREGIOUS
    S21_S(EGREGIOUS, "You really blew it this time")
    #endif
    #ifdef EPROCLIM
    S21_S(EPROCLIM, "Too many processes")
    #endif
    #ifdef EGRATUITOUS
    S21_S(EGRATUITOUS, "Gratuitous error")
    #endif
    #if defined (ENOTSUP) && ENOTSUP != EOPNOTSUPP
    S21_S(ENOTSUP, "Not supported")
    #endif
    #ifdef EPROGMISMATCH
    S21_S(EPROGMISMATCH, "RPC program version wrong")
    #endif
    #ifdef EBACKGROUND
    S21_S(EBACKGROUND, "Inappropriate operation for background process")
    #endif
    #ifdef EIEIO
    S21_S(EIEIO, "Computer bought the farm")
    #endif
    #if defined (EWOULDBLOCK) && EWOULDBLOCK != EAGAIN
    S21_S(EWOULDBLOCK, "Operation would block")
    #endif
    #ifdef ENEEDAUTH
    S21_S(ENEEDAUTH, "Need authenticator")
    #endif
    #ifdef EPROGUNAVAIL
    S21_S(EPROGUNAVAIL, "RPC program not available")
    #endif
#endif  // _S21_LINUX_ERRLIST_H_