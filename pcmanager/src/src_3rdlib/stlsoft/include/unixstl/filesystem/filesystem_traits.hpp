/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/filesystem_traits.hpp
 *
 * Purpose:     Contains the filesystem_traits template class, and ANSI and
 *              Unicode specialisations thereof.
 *
 * Created:     15th November 2002
 * Updated:     21st June 2010
 *
 * Thanks:      To Sergey Nikulov, for spotting a pre-processor typo that
 *              broke GCC -pedantic
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2010, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file unixstl/filesystem/filesystem_traits.hpp
 *
 * \brief [C++ only] Definition of the unixstl::filesystem_traits traits
 *  class
 *   (\ref group__library__filesystem "File System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_MAJOR     4
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_MINOR     4
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_REVISION  1
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS_EDIT      111
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS
# include <unixstl/system/system_traits.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS */

#ifdef _WIN32
# include <ctype.h>
#endif /* _WIN32 */
#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */
#ifndef STLSOFT_INCL_H_FCNTL
# define STLSOFT_INCL_H_FCNTL
# include <fcntl.h>
#endif /* !STLSOFT_INCL_H_FCNTL */
#ifdef _WIN32
# include <io.h>
# if defined(STLSOFT_COMPILER_IS_INTEL) || \
     defined(STLSOFT_COMPILER_IS_MSVC)
#  include <direct.h>
# endif /* os && compiler */
#endif /* _WIN32 */
#ifndef STLSOFT_INCL_H_DLFCN
# define STLSOFT_INCL_H_DLFCN
# include <dlfcn.h>
#endif /* !STLSOFT_INCL_H_DLFCN */
#ifndef STLSOFT_INCL_H_DIRENT
# define STLSOFT_INCL_H_DIRENT
# include <dirent.h>
#endif /* !STLSOFT_INCL_H_DIRENT */
#ifndef STLSOFT_INCL_H_LIMITS
# define STLSOFT_INCL_H_LIMITS
# include <limits.h>
#endif /* !STLSOFT_INCL_H_LIMITS */
#ifndef STLSOFT_INCL_H_STDIO
# define STLSOFT_INCL_H_STDIO
# include <stdio.h>
#endif /* !STLSOFT_INCL_H_STDIO */
#ifndef STLSOFT_INCL_H_STDLIB
# define STLSOFT_INCL_H_STDLIB
# include <stdlib.h>
#endif /* !STLSOFT_INCL_H_STDLIB */
#ifndef STLSOFT_INCL_H_STRING
# define STLSOFT_INCL_H_STRING
# include <string.h>
#endif /* !STLSOFT_INCL_H_STRING */
#ifndef STLSOFT_INCL_H_UNISTD
# define STLSOFT_INCL_H_UNISTD
# include <unistd.h>
#endif /* !STLSOFT_INCL_H_UNISTD */
#ifndef STLSOFT_INCL_H_WCHAR
# define STLSOFT_INCL_H_WCHAR
# include <wchar.h>
#endif /* !STLSOFT_INCL_H_WCHAR */
#ifndef STLSOFT_INCL_SYS_H_TYPES
# define STLSOFT_INCL_SYS_H_TYPES
# include <sys/types.h>
#endif /* !STLSOFT_INCL_SYS_H_TYPES */
#ifndef STLSOFT_INCL_SYS_H_STAT
# define STLSOFT_INCL_SYS_H_STAT
# include <sys/stat.h>
#endif /* !STLSOFT_INCL_SYS_H_STAT */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */

namespace stlsoft
{

namespace unixstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
/** \brief Traits class for file-system operations
 *
 * \ingroup group__library__filesystem
 *
 * filesystem_traits is a traits class for determining the correct file-system
 * structures and functions for a given character type.
 *
 * \param C The character type (e.g. \c char, \c wchar_t)
 */
template <ss_typename_param_k C>
struct filesystem_traits
    : public system_traits<C>
{
/// \name Types
/// @{
private:
    typedef system_traits<C>                        parent_class_type;
public:
    /// \brief The character type
    typedef C                                       char_type;
    /// \brief The size type
    typedef us_size_t                               size_type;
    /// \brief The difference type
    typedef us_ptrdiff_t                            difference_type;
    /// \brief The stat data type
    typedef struct stat                             stat_data_type;
    /// \brief The fstat data type
    typedef struct stat                             fstat_data_type;
    /// \brief The current instantion of the type
    typedef filesystem_traits<C>                    class_type;
    /// \brief The (signed) integer type
    typedef us_int_t                                int_type;
    /// \brief The Boolean type
    typedef us_bool_t                               bool_type;
    /// \brief The type of a system file handle
    typedef int                                     file_handle_type;
    /// \brief The type of a handle to a dynamically loaded module
    typedef void*                                   module_type;
    /// \brief The type of system error codes
    typedef int                                     error_type;
    /// \brief The mode type
#ifdef _WIN32
    typedef unsigned short                          mode_type;
#else /* ? _WIN32 */
    typedef mode_t                                  mode_type;
#endif /* _WIN32 */
/// @}

#ifdef PATH_MAX
/// \name Member Constants
/// @{
public:
    enum
    {
        maxPathLength   =   1 + PATH_MAX    //!< The maximum length of a path for the current file system
    };

    enum
    {
#ifdef _WIN32
        pathComparisonIsCaseSensitive   =   false
#else
        pathComparisonIsCaseSensitive   =   true
#endif
    };
/// @}
#endif /* PATH_MAX */

/// \name General string handling
/// @{
public:
    /// Compares the contents of \c src and \c dest, according to the
      /// lexicographical ordering on the host operating system.
    static int_type     str_fs_compare(char_type const* s1, char_type const* s2);
    /// Compares the contents of \c src and \c dest up to \c cch
    /// characters. according to the lexicographical ordering on the host
    /// operating system.
    static int_type     str_fs_n_compare(char_type const* s1, char_type const* s2, size_type cch);
/// @}

/// \name File-system entry names
/// @{
public:
    /// \brief Appends a path name separator to \c dir if one does not exist
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static char_type*   ensure_dir_end(char_type* dir);
    /// \brief Removes the path name separator from the end of \c dir, if it has it
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static char_type*   remove_dir_end(char_type* dir);
    /// \brief Returns \c true if \c dir has trailing path name separator
    ///
    /// \see \link #path_name_separator path_name_separator() \endlink
    static bool_type    has_dir_end(char_type const* dir);

    /// \brief Returns \c true if dir is \c "." or \c ".."
    static bool_type    is_dots(char_type const* dir);
    /// \brief Returns \c true if path is rooted
    ///
    /// \note Only enough characters of the path pointed to by \c path as are
    /// necessary to detect the presence or absence of the operating system's
    /// root character sequence(s).
    static bool_type    is_path_rooted(char_type const* path);
    /// \brief Returns \c true if path is an absolute path
    ///
    /// \note Only enough characters of the path pointed to by \c path as are
    /// necessary to detect the presence or absence of the operating system's
    /// absolute path character sequence(s).
    static bool_type    is_path_absolute(char_type const* path);
    /// \brief Returns \c true if path is a UNC path
    ///
    /// \note Only enough characters of the path pointed to by \c path as are
    /// necessary to detect the presence or absence of the UNC character sequence(s).
    static bool_type    is_path_UNC(char_type const* path);
    /// \brief Indicates whether the given path is the root designator.
    ///
    /// The root designator is one of the following:
    ///  - the slash character <code>/</code>
    ///
    /// The function returns false if the path contains any part of a
    /// file name (or extension), directory, or share.
    static bool_type    is_root_designator(char_type const* path);
    /// \brief Returns \c true if the character is a path-name separator
    static bool_type    is_path_name_separator(char_type ch);

    /// \brief Returns the path separator
    ///
    /// This is the separator that is used to separate multiple paths on the operating system. On UNIX it is ':'
    static char_type    path_separator();
    /// \brief Returns the path name separator
    ///
    /// This is the separator that is used to separate parts of a path on the operating system. On UNIX it is '/'
    static char_type    path_name_separator();
    /// \brief Returns the wildcard pattern that represents all possible matches
    ///
    /// \note On UNIX it is '*'
    static char_type const* pattern_all();
    /// \brief The maximum length of a path on the file-system
    ///
    /// \note Because not all systems support fixed maximum path lengths, the value of this function is notionally dynamic
    static size_type    path_max();
    /// \brief Gets the full path name into the given buffer, returning a pointer to the file-part
    static size_type    get_full_path_name(char_type const* fileName, size_type cchBuffer, char_type* buffer, char_type** ppFile);
    /// \brief Gets the full path name into the given buffer
    static size_type    get_full_path_name(char_type const* fileName, char_type* buffer, size_type cchBuffer);
    /// \brief Gets the full path name into the given buffer
    ///
    /// \deprecated The other overload is now the preferred form
    static size_type    get_full_path_name(char_type const* fileName, size_type cchBuffer, char_type* buffer);
    /// \brief Gets the short path name into the given buffer
    static size_type    get_short_path_name(char_type const* fileName, size_type cchBuffer, char_type* buffer);
/// @}

/// \name File-system enumeration
/// @{
public:
    // opendir/readdir API

    /// \brief Initiate a file-system search
    static DIR*                 open_dir(char_type const* dir);
    /// \brief Read an entry from the file-system search
    static struct dirent const* read_dir(DIR *h);
    /// \brief Closes the handle of the file-system search
    static void                 close_dir(DIR *h);

/// @}

/// \name File-system control
/// @{
public:
    /// \brief Sets the current directory to \c dir
    static bool_type    set_current_directory(char_type const* dir);
    /// \brief Retrieves the name of the current directory into \c buffer up to a maximum of \c cchBuffer characters
    ///
    /// \deprecated The other overload is now the preferred form
    static size_type    get_current_directory(size_type cchBuffer, char_type* buffer);
    /// \brief Retrieves the name of the current directory into \c buffer up to a maximum of \c cchBuffer characters
    static size_type    get_current_directory(char_type* buffer, size_type cchBuffer);
/// @}

/// \name File-system state
/// @{
public:
    /// \brief Returns whether a file exists or not
    static bool_type    file_exists(char_type const* path);
    /// \brief Returns whether the given path represents a file
    static bool_type    is_file(char_type const* path);
    /// \brief Returns whether the given path represents a directory
    static bool_type    is_directory(char_type const* path);
    /// \brief Gets the information for a particular file system entry
    static bool_type    stat(char_type const* path, stat_data_type *stat_data);
    /// \brief Gets the information for a particular file system entry
    static bool_type    lstat(char_type const* path, stat_data_type *stat_data);
    /// \brief Gets the information for a particular open file
    static bool_type    fstat(file_handle_type fd, fstat_data_type *fstat_data);

    /// \brief Returns whether the given stat info represents a file
    static bool_type    is_file(stat_data_type const* stat_data);
    /// \brief Returns whether the given stat info represents a directory
    static bool_type    is_directory(stat_data_type const* stat_data);
    /// \brief Returns whether the given stat info represents a link
    static bool_type    is_link(stat_data_type const* stat_data);
    /// \brief Returns whether the given stat info represents a read-only entry
    static bool_type    is_readonly(stat_data_type const* stat_data);
/// @}

/// \name File-system control
/// @{
public:
    /// \brief Creates a directory
    static bool_type    create_directory(char_type const* dir);
    /// \brief Deletes a directory
    static bool_type    remove_directory(char_type const* dir);

    /// \brief Delete a file
    static bool_type    unlink_file(char_type const* file);
    /// \brief Delete a file
    ///
    /// \deprecated Users should use unlink_file()
    static bool_type    delete_file(char_type const* file);
    /// \brief Rename a file
    static bool_type    rename_file(char_type const* currentName, char_type const* newName);
    /// \brief Copy a file
//    static bool_type    copy_file(char_type const* sourceName, char_type const* newName, bool_type bFailIfExists = false);

    /// \brief Create / open a file
    static file_handle_type open_file(char_type const* fileName, int oflag, int pmode);
    /// \brief Closes the given operating system handle
    static bool_type        close_file(file_handle_type fd);
    /// \brief Create / open a file
    ///
    /// \deprecated Users should use open_file()
    static file_handle_type open(char_type const* fileName, int oflag, int pmode);
    /// \brief Closes the given operating system handle
    ///
    /// \deprecated Users should use close_file()
    static bool_type        close(file_handle_type fd);
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    /// \brief Gets the size of the file
    static us_uint64_t      get_file_size(file_handle_type fd);
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
/// @}
};

#else /* ? STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k C>
struct filesystem_traits;

STLSOFT_TEMPLATE_SPECIALISATION
struct filesystem_traits<us_char_a_t>
    : public system_traits<us_char_a_t>
{
public:
    typedef us_char_a_t                                 char_type;
    typedef us_size_t                                   size_type;
    typedef us_ptrdiff_t                                difference_type;
    typedef struct stat                                 stat_data_type;
    typedef struct stat                                 fstat_data_type;
    typedef filesystem_traits<us_char_a_t>              class_type;
    typedef us_int_t                                    int_type;
    typedef us_bool_t                                   bool_type;
    typedef int                                         file_handle_type;
    typedef void*                                       module_type;
    typedef int                                         error_type;
#ifdef _WIN32
    typedef unsigned short                              mode_type;
#else /* ? _WIN32 */
    typedef mode_t                                      mode_type;
#endif /* _WIN32 */
private:
    typedef stlsoft_ns_qual(auto_buffer_old)<char_type> buffer_type_;
public:


#ifdef PATH_MAX
    enum
    {
        maxPathLength   =   1 + PATH_MAX    //!< The maximum length of a path for the current file system
    };
#endif /* PATH_MAX */

public:
    static int_type str_fs_compare(char_type const* s1, char_type const* s2)
    {
#ifdef _WIN32
        return str_compare_no_case(s1, s2);
#else
        return str_compare(s1, s2);
#endif
    }

    static int_type str_fs_n_compare(char_type const* s1, char_type const* s2, size_type cch)
    {
#ifdef _WIN32
        return str_n_compare_no_case(s1, s2, cch);
#else
        return str_n_compare(s1, s2, cch);
#endif
    }

    static char_type* ensure_dir_end(char_type* dir)
    {
        UNIXSTL_ASSERT(NULL != dir);

        char_type* end = str_end(dir);

        if( dir < end &&
            !is_path_name_separator(*(end - 1)))
        {
            *end        =   path_name_separator();
            *(end + 1)  =   '\0';
        }

        return dir;
    }

    static char_type* remove_dir_end(char_type* dir)
    {
        UNIXSTL_ASSERT(NULL != dir);

#ifdef _WIN32
        // Don't trim drive roots ...
        if( isalpha(dir[0]) &&
            ':' == dir[1] &&
            is_path_name_separator(dir[2]) &&
            '\0' == dir[3])
        {
            return dir;
        }

        // ... or UNC roots
        if( '\\' == dir[0] &&
            '\\' == dir[1] &&
            '\0' == dir[3])
        {
            return dir;
        }
#endif /* _WIN32 */

        char_type* end = str_end(dir);

        if( dir < end &&
            is_path_name_separator(*(end - 1)))
        {
            *(end - 1)  =   '\0';
        }

        return dir;
    }

    static bool_type has_dir_end(char_type const* dir)
    {
        UNIXSTL_ASSERT(NULL != dir);

        size_type len = str_len(dir);

        return (0 < len) && is_path_name_separator(dir[len - 1]);
    }

    static bool_type is_dots(char_type const* dir)
    {
        UNIXSTL_ASSERT(NULL != dir);

        return  dir[0] == '.' &&
                (   dir[1] == '\0' ||
                    (    dir[1] == '.' &&
                        dir[2] == '\0'));
    }

    static bool_type is_path_rooted(char_type const* path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef _WIN32
        // It might be a UNC path. This is handled by the second test below, but
        // this is a bit clearer, and since this is a debug kind of thing, we're
        // not worried about the cost
        if( '\\' == path[0] &&
            '\\' == path[1])
        {
            return true;
        }

        // If it's really on Windows, then we need to skip the drive, if present
        if( isalpha(path[0]) &&
            ':' == path[1])
        {
            path += 2;
        }

        // If it's really on Windows, then we need to account for the fact that
        // the slash might be backwards, but that's taken care of for us by
        // is_path_name_separator()
#endif /* _WIN32 */

        return is_path_name_separator(*path);
    }

    static bool_type is_path_absolute(char_type const* path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef _WIN32
        // If it's really on Windows, then it can only be absolute if ...
        //
        // ... it's a UNC path, or ...
        if(is_path_UNC(path))
        {
            return true;
        }
        // ... it's got drive + root slash, or
        if( isalpha(path[0]) &&
            ':' == path[1] &&
            is_path_name_separator(path[2]))
        {
            return true;
        }
        // ... it's got root forward slash
        if('/' == path[0])
        {
            return true;
        }

        return false;
#else /* ? _WIN32 */
        return is_path_rooted(path);
#endif /* _WIN32 */
    }

    static bool_type is_path_UNC(char_type const* path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef _WIN32
        return ('\\' == path[0] && '\\' == path[1]);
#else /* ? _WIN32 */
        STLSOFT_SUPPRESS_UNUSED(path);

        return false;
#endif /* _WIN32 */
    }

private:
    static bool_type is_root_drive_(char_type const* path)
    {
#ifdef _WIN32
        if( isalpha(path[0]) &&
            ':' == path[1] &&
            is_path_name_separator(path[2]) &&
            '\0' == path[3])
        {
            return true;
        }
#else /* ? _WIN32 */
        STLSOFT_SUPPRESS_UNUSED(path);
#endif /* _WIN32 */

        return false;
    }
    static bool_type is_root_UNC_(char_type const* path)
    {
#ifdef _WIN32
        if(is_path_UNC(path))
        {
            char_type const* sep = str_pbrk(path + 2, "\\/");

            if( NULL == sep ||
                '\0' == sep[1])
            {
                return true;
            }
        }
#else /* ? _WIN32 */
        STLSOFT_SUPPRESS_UNUSED(path);
#endif /* _WIN32 */

        return false;
    }
    static bool_type is_root_directory_(char_type const* path)
    {
        if( is_path_name_separator(path[0]) &&
            '\0' == path[1])
        {
            return true;
        }

        return false;
    }
public:
    static bool_type is_root_designator(char_type const* path)
    {
        UNIXSTL_ASSERT(NULL != path);

        return is_root_directory_(path) || is_root_drive_(path) || is_root_UNC_(path);
    }

    static bool_type is_path_name_separator(char_type ch)
    {
#ifdef _WIN32
        return '\\' == ch || '/' == ch;
#else /* ? _WIN32 */
        return '/' == ch;
#endif /* _WIN32 */
    }

    static char_type path_separator()
    {
        return ':';
    }

    static char_type path_name_separator()
    {
        return '/';
    }

    static char_type const* pattern_all()
    {
        return "*";
    }

    static size_type path_max()
    {
#if defined(PATH_MAX)
        return 1 + PATH_MAX;
#else /* ? PATH_MAX */
        return 1 + pathconf("/", _PC_PATH_MAX);
#endif /* PATH_MAX */
    }

private:
    static size_type get_full_path_name_impl2(char_type const* fileName, us_size_t len, char_type* buffer, size_type cchBuffer)
    {
        // The next thing to so is determine whether the path is absolute, in
        // which case we'll just copy it into the buffer
        if(is_path_rooted(fileName))
        {
            // Given path is absolute, so simply copy into buffer
            if(NULL == buffer)
            {
                len = len;
            }
            else if(cchBuffer < len)
            {
                char_copy(&buffer[0], fileName, cchBuffer);
                len = cchBuffer;
            }
            else
            {
                // Given buffer is large enough, so copy
                char_copy(&buffer[0], fileName, len);
                buffer[len] = '\0';
            }
        }
        else
        {
            // Given path is relative, so get the current directory, and then concatenate
            buffer_type_    directory(1 + path_max());

            if(0 == directory.size())
            {
                set_last_error(ENOMEM);

                return 0;
            }
            else if(NULL != buffer &&
                    0 == cchBuffer)
            {
                return 0;
            }
            else
            {
                size_type lenDir = get_current_directory(&directory[0], directory.size());

                if(0 == lenDir)
                {
                    // The call failed, so indicate that to caller
                    len = 0;
                }
                else
                {
                    if( 1 == len &&
                        '.' == fileName[0])
                    {
                        if(NULL == buffer)
                        {
                            len = lenDir;
                        }
                        else
                        {
                            if(cchBuffer < lenDir)
                            {
                                char_copy(&buffer[0], directory.data(), cchBuffer);
                                len = cchBuffer;
                            }
                            else
                            {
                                // Given buffer is large enough, so copy
                                char_copy(buffer, directory.data(), lenDir);
                                buffer[lenDir] = '\0';
                                len = lenDir;
                            }
                        }
                    }
                    else
                    {
                        if(!has_dir_end(&directory[0] + (lenDir - 1)))
                        {
                            ++lenDir;
                        }
                        ensure_dir_end(&directory[0]);

                        len += lenDir;

                        if(NULL != buffer)
                        {
                            char_copy(&buffer[0], directory.data(), cchBuffer);

                            if(cchBuffer > lenDir)
                            {
                                char_copy(&buffer[0] + lenDir, fileName, cchBuffer - lenDir);
                            }

                            if(cchBuffer < len)
                            {
                                len = cchBuffer;
                            }
                        }
                    }
                }
            }
        }

        return len;
    }

    static size_type get_full_path_name_impl(char_type const* fileName, us_size_t len, char_type* buffer, size_type cchBuffer)
    {
        UNIXSTL_ASSERT(len > 0);

        if(NULL != class_type::str_pbrk(fileName, "<>|*?"))
        {
            errno = ENOENT;

            return 0;
        }

        if('\0' != fileName[len])
        {
            buffer_type_    fileName_(1 + (len - 1));

            // May be being compiled absent exception support, so need to check the
            // file path buffers. (This _could_ be done with a compile-time #ifdef,
            // but it's best not, since some translators support exceptions but yet
            // don't throw on mem exhaustion, and in any case a user could change
            // ::new)
            if(0 == fileName_.size())
            {
                set_last_error(ENOMEM);

                return 0;
            }
            else
            {
                fileName_[len] = '\0';

                return get_full_path_name_impl2(char_copy(&fileName_[0], fileName, len)
                                            ,   len
                                            ,   buffer
                                            ,   cchBuffer);
            }
        }
        else
        {
            return get_full_path_name_impl2(fileName, len, buffer, cchBuffer);
        }
    }

public:
    static size_type get_full_path_name(char_type const* fileName, size_type cchBuffer, char_type* buffer, char_type** ppFile)
    {
        UNIXSTL_ASSERT(NULL != ppFile);

        size_type r = get_full_path_name(fileName, buffer, cchBuffer);

        *ppFile = NULL;

        if( NULL != buffer &&
            0 != r &&
            r <= cchBuffer)
        {
            size_type cchRequired = get_full_path_name(fileName, static_cast<char_type*>(NULL), 0);

            if(r == cchRequired)
            {
                // Now search for the file separator
                char_type* pFile        =   str_rchr(buffer, path_name_separator());
#if defined(_WIN32)
                char_type* pFile2       =   str_rchr(buffer, '\\');

                if(NULL == pFile)
                {
                    pFile = pFile2;
                }
                else if(NULL != pFile2)
                {
                    if(pFile2 > pFile)
                    {
                        pFile = pFile2;
                    }
                }
#endif /* _WIN32 */

                if(NULL != (*ppFile = pFile))
                {
                    (*ppFile)++;
                }
            }
        }

        return r;
    }

    static size_type get_full_path_name(char_type const* fileName, char_type* buffer, size_type cchBuffer)
    {
        UNIXSTL_ASSERT(NULL != fileName);
        UNIXSTL_ASSERT(0 == cchBuffer || NULL != buffer);

        if('\0' == *fileName)
        {
            static const char   s_dot[2] = { '.', '\0' };

            fileName = s_dot;
        }

        // Can't call realpath(), since that requires that the file exists
        return get_full_path_name_impl(fileName, str_len(fileName), buffer, cchBuffer);
    }

    static size_type get_full_path_name(char_type const* fileName, size_type cchBuffer, char_type* buffer)
    {
        return get_full_path_name(fileName, buffer, cchBuffer);
    }

    static size_type get_short_path_name(char_type const* fileName, size_type cchBuffer, char_type* buffer)
    {
        return get_full_path_name(fileName, cchBuffer, buffer);
    }

    // File-system enumeration

    static DIR *open_dir(char_type const* dir)
    {
        return ::opendir(dir);
    }
    static struct dirent const* read_dir(DIR *h)
    {
        return ::readdir(h);
    }
    static void close_dir(DIR *h)
    {
        ::closedir(h);
    }

    // File-system state
    static bool_type set_current_directory(char_type const* dir)
    {
#if defined(_WIN32) && \
    (   defined(STLSOFT_COMPILER_IS_MSVC) || \
        defined(STLSOFT_COMPILER_IS_INTEL))
        return 0 == ::_chdir(dir);
#else /* ? _WIN32 */
        return 0 == ::chdir(dir);
#endif /* _WIN32 */
    }

    static size_type get_current_directory(size_type cchBuffer, char_type* buffer)
    {
        return get_current_directory(buffer, cchBuffer);
    }

    static size_type get_current_directory(char_type* buffer, size_type cchBuffer)
    {
#if defined(_WIN32) && \
    (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC))
        char_type const* dir = ::_getcwd(buffer, int(cchBuffer));
#else /* ? _WIN32 */
        char_type const* dir = ::getcwd(buffer, int(cchBuffer));
#endif /* _WIN32 */

        return (NULL == dir) ? 0 : str_len(dir);
    }

    static bool_type file_exists(char_type const* fileName)
    {
        stat_data_type  sd;

        return class_type::stat(fileName, &sd) /* || errno != ENOENT */;
    }

    static bool_type is_file(char_type const* path)
    {
        stat_data_type  sd;

        return class_type::stat(path, &sd) && S_IFREG == (sd.st_mode & S_IFMT);
    }

    static bool_type is_directory(char_type const* path)
    {
        stat_data_type  sd;

        return class_type::stat(path, &sd) && S_IFDIR == (sd.st_mode & S_IFMT);
    }

    static bool_type stat(char_type const* path, stat_data_type *stat_data)
    {
        UNIXSTL_ASSERT(NULL != path);
        UNIXSTL_ASSERT(NULL != stat_data);

#ifdef _WIN32
        if(NULL != class_type::str_pbrk(path, "*?"))
        {
            // Sometimes the VC6 CRT libs crash with a wildcard stat
            set_last_error(EBADF);

            return false;
        }

        if(has_dir_end(path))
        {
            // Win32 impl does not like a trailing slash
            size_type   len =   str_len(path);

            if( len > 3 ||
                (   is_path_name_separator(*path) &&
                    len > 2))
            {
                buffer_type_    directory(1 + len);

                if(0 == directory.size())
                {
                    set_last_error(ENOMEM);

                    return false;
                }
                else
                {
                    char_copy(&directory[0], path, len);
                    directory[len] = '\0';

                    class_type::remove_dir_end(&directory[0]);

                    return class_type::stat(directory.data(), stat_data);
                }
            }
        }
#endif /* _WIN32 */

        return 0 == ::stat(path, stat_data);
    }

    static bool_type lstat(char_type const* path, stat_data_type *stat_data)
    {
        UNIXSTL_ASSERT(NULL != path);
        UNIXSTL_ASSERT(NULL != stat_data);

#ifdef _WIN32
        return 0 == class_type::stat(path, stat_data);
#else /* ? _WIN32 */
        return 0 == ::lstat(path, stat_data);
#endif /* _WIN32 */
    }

    static bool_type fstat(file_handle_type fd, fstat_data_type *fstat_data)
    {
        UNIXSTL_ASSERT(-1 != fd);
        UNIXSTL_ASSERT(NULL != fstat_data);

        return 0 == ::fstat(fd, fstat_data);
    }

    static bool_type is_file(stat_data_type const* stat_data)
    {
        return S_IFREG == (stat_data->st_mode & S_IFREG);
    }
    static bool_type is_directory(stat_data_type const* stat_data)
    {
        return S_IFDIR == (stat_data->st_mode & S_IFDIR);
    }
    static bool_type is_link(stat_data_type const* stat_data)
    {
#ifdef _WIN32
        STLSOFT_SUPPRESS_UNUSED(stat_data);

        return false;
#else /* ? _WIN32 */
        return S_IFLNK == (stat_data->st_mode & S_IFLNK);
#endif /* _WIN32 */
    }
    static bool_type is_readonly(stat_data_type const* stat_data)
    {
#ifdef _WIN32
        return S_IREAD == (stat_data->st_mode & (S_IREAD | S_IWRITE));
#else /* ? _WIN32 */
        return S_IRUSR == (stat_data->st_mode & (S_IRUSR | S_IWUSR));
#endif /* _WIN32 */
    }

    static bool_type    create_directory(char_type const* dir)
    {
        mode_type   mode = 0;

#ifdef _WIN32
        mode    =   S_IREAD | S_IWRITE | S_IEXEC;
#else /* ? _WIN32 */
        mode    =   S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;
#endif /* _WIN32 */

        return create_directory(dir, 0);
    }

    static bool_type create_directory(char_type const* dir, mode_type permissions)
    {
#if defined(_WIN32) && \
    (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC))

        STLSOFT_SUPPRESS_UNUSED(permissions);

        return 0 == ::_mkdir(dir);
#else /* ? _WIN32 */
        return 0 == ::mkdir(dir, permissions);
#endif /* _WIN32 */
    }

    static bool_type remove_directory(char_type const* dir)
    {
#if defined(_WIN32) && \
    (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC))
        return 0 == ::_rmdir(dir);
#else /* ? _WIN32 */
        return 0 == ::rmdir(dir);
#endif /* _WIN32 */
    }

    static bool_type unlink_file(char_type const* file)
    {
        return 0 == ::remove(file);
    }

    static bool_type    delete_file(char_type const* file)
    {
        return unlink_file(file);
    }

    static bool_type rename_file(char_type const* currentName, char_type const* newName)
    {
        return 0 == ::rename(currentName, newName);
    }

#if (   defined(STLSOFT_COMPILER_IS_MSVC) || \
        defined(STLSOFT_COMPILER_IS_INTEL)) && \
    defined(STLSOFT_USING_SAFE_STR_FUNCTIONS)
# if _MSC_VER >= 1200
#  pragma warning(push)
# endif /* compiler */
# pragma warning(disable : 4996)
#endif /* compiler */

    static file_handle_type open_file(char_type const* fileName, int oflag, int pmode)
    {
#if defined(_WIN32) && \
    (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC))
        return ::_open(fileName, oflag, pmode);
#else /* ? _WIN32 */
        return ::open(fileName, oflag, pmode);
#endif /* _WIN32 */
    }

#if (   defined(STLSOFT_COMPILER_IS_MSVC) || \
        defined(STLSOFT_COMPILER_IS_INTEL)) && \
    defined(STLSOFT_USING_SAFE_STR_FUNCTIONS)
# if _MSC_VER >= 1200
#  pragma warning(pop)
# else /* ? compiler */
#  pragma warning(default : 4996)
# endif /* _MSC_VER */
#endif /* compiler */

    static bool_type close_file(file_handle_type fd)
    {
#if defined(_WIN32) && \
    (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC))
        return 0 == ::_close(fd);
#else /* ? _WIN32 */
        return 0 == ::close(fd);
#endif /* _WIN32 */
    }

    static file_handle_type open(char_type const* fileName, int oflag, int pmode)
    {
        return class_type::open_file(fileName, oflag, pmode);
    }

    static bool_type close(file_handle_type fd)
    {
        return class_type::close_file(fd);
    }

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    static us_uint64_t get_file_size(file_handle_type fd)
    {
        struct stat st;

        return class_type::fstat(fd, &st) ? st.st_size : 0;
    }
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
};

STLSOFT_TEMPLATE_SPECIALISATION
struct filesystem_traits<us_char_w_t>
    : public system_traits<us_char_w_t>
{
public:
    typedef us_char_w_t char_type;
    typedef us_size_t   size_type;

#ifdef PATH_MAX
    enum
    {
        maxPathLength   =   1 + PATH_MAX    //!< The maximum length of a path for the current file system
    };
#endif /* PATH_MAX */

public:
    static int_type str_fs_compare(char_type const* s1, char_type const* s2)
    {
#ifdef _WIN32
        return str_compare_no_case(s1, s2);
#else
        return str_compare(s1, s2);
#endif
    }

    static int_type str_fs_n_compare(char_type const* s1, char_type const* s2, size_type cch)
    {
#ifdef _WIN32
        return str_n_compare_no_case(s1, s2, cch);
#else
        return str_n_compare(s1, s2, cch);
#endif
    }

    static char_type* ensure_dir_end(char_type* dir)
    {
        UNIXSTL_ASSERT(NULL != dir);

        char_type* end = str_end(dir);

        if( dir < end &&
            !is_path_name_separator(*(end - 1)))
        {
            *end        =   path_name_separator();
            *(end + 1)  =   L'\0';
        }

        return dir;
    }

    static char_type* remove_dir_end(char_type* dir)
    {
        UNIXSTL_ASSERT(NULL != dir);

#ifdef _WIN32
        // Don't trim drive roots ...
        if( isalpha(dir[0]) &&
            L':' == dir[1] &&
            is_path_name_separator(dir[2]) &&
            L'\0' == dir[3])
        {
            return dir;
        }

        // ... or UNC roots
        if( L'\\' == dir[0] &&
            L'\\' == dir[1] &&
            L'\0' == dir[3])
        {
            return dir;
        }
#endif /* _WIN32 */

        char_type* end = str_end(dir);

        if( dir < end &&
            is_path_name_separator(*(end - 1)))
        {
            *(end - 1)  =   L'\0';
        }

        return dir;
    }

    static bool_type has_dir_end(char_type const* dir)
    {
        UNIXSTL_ASSERT(NULL != dir);

        size_type len = str_len(dir);

        return (0 < len) && is_path_name_separator(dir[len - 1]);
    }

    static bool_type is_dots(char_type const* dir)
    {
        UNIXSTL_ASSERT(NULL != dir);

        return  dir[0] == '.' &&
                (   dir[1] == L'\0' ||
                    (    dir[1] == L'.' &&
                        dir[2] == L'\0'));
    }

    static bool_type is_path_rooted(char_type const* path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef _WIN32
        // If it's really on Windows, then we need to skip the drive, if present
        if( isalpha(path[0]) &&
            ':' == path[1])
        {
            path += 2;
        }

        // If it's really on Windows, then we need to account for the fact that
        // the slash might be backwards
        if('\\' == *path)
        {
            return true;
        }
#endif /* _WIN32 */

        return '/' == *path;
    }

    static bool_type is_path_absolute(char_type const* path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef _WIN32
        // If it's really on Windows, then it can only be absolute if ...
        //
        // ... it's a UNC path, or ...
        if(is_path_UNC(path))
        {
            return true;
        }
        // ... it's got drive + root slash, or
        if( isalpha(path[0]) &&
            ':' == path[1] &&
            is_path_name_separator(path[2]))
        {
            return true;
        }
        // ... it's got root forward slash
        if('/' == path[0])
        {
            return true;
        }

        return false;
#else /* ? _WIN32 */
        return is_path_rooted(path);
#endif /* _WIN32 */
    }

    static bool_type is_path_UNC(char_type const* path)
    {
        UNIXSTL_ASSERT(NULL != path);

#ifdef _WIN32
        return (L'\\' == path[0] && L'\\' == path[1]);
#else /* ? _WIN32 */
        STLSOFT_SUPPRESS_UNUSED(path);

        return false;
#endif /* _WIN32 */
    }

    static bool_type is_path_name_separator(char_type ch)
    {
#ifdef _WIN32
        return L'\\' == ch || L'/' == ch;
#else /* ? _WIN32 */
        return L'/' == ch;
#endif /* _WIN32 */
    }

    static char_type path_separator()
    {
        return L':';
    }

    static char_type path_name_separator()
    {
        return L'/';
    }

    static char_type const* pattern_all()
    {
        return L"*";
    }

    static size_type path_max()
    {
#if defined(PATH_MAX)
        return 1 + PATH_MAX;
#else /* ? PATH_MAX */
        return 1 + pathconf("/", _PC_PATH_MAX);
#endif /* PATH_MAX */
    }

#if 0
    static size_type get_full_path_name(char_type const* fileName, size_type cchBuffer, char_type* buffer, char_type** ppFile);

    static size_type get_full_path_name(char_type const* fileName, char_type* buffer, size_type cchBuffer)
    {
        char_type* pFile;

        return get_full_path_name(fileName, cchBuffer, buffer, &pFile);
    }

    static size_type get_full_path_name(char_type const* fileName, size_type cchBuffer, char_type* buffer)
    {
        return get_full_path_name(fileName, buffer, cchBuffer);
    }

    static size_type get_short_path_name(char_type const* fileName, size_type cchBuffer, char_type* buffer)
    {
        return get_full_path_name(fileName, cchBuffer, buffer);
    }
#endif /* 0 */

    // File-system state
    static bool_type set_current_directory(char_type const* dir);

    static size_type get_current_directory(size_type cchBuffer, char_type* buffer);

    static size_type get_current_directory(char_type* buffer, size_type cchBuffer);
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Unit-testing
 */

#ifdef STLSOFT_UNITTEST
# include "./unittest/filesystem_traits_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */
