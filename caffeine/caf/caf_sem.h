/* -*- mode: c; c-default-style: "k&r"; indent-tabs-mode: nil; -*- */
/* vim:set ft=c ff=unix ts=4 sw=4 enc=latin1 expandtab: */
/* kate: space-indent on; indent-width 4; mixedindent off; indent-mode none; */
/*
    Caffeine - C Application Framework
    Copyright (C) 2006 Daniel Molina Wegener

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
    MA 02110-1301 USA

    $Id: caf_sem.h 184 2007-02-02 19:23:33Z dmw $
 */
#ifndef CAF_SEM_H
#define CAF_SEM_H 1
/**
 * @defgroup      caf_sem           Semaphores Management
 * @ingroup       caf_ipc
 * @addtogroup    caf_sem
 * @{
 *
 * @brief     Semaphores Management
 * @date      $Date: 2007-02-02 16:23:33 -0300 (Fri, 02 Feb 2007) $
 * @version   $Revision: 184 $
 * @author    Daniel Molina Wegener <dmw@unete.cl>
 *
 * Semaphores Management
 *
 */

#include <stdlib.h>
#include <stdio.h>

#ifdef CAF_USE_POSIX_SEMAPHORES
#include <caf/caf_sem_posix.h>

#define CAF_SEM_NEW(k,f,v)          caf_sem_posix_new (k,f,v)
#define CAF_SEM_GET(k,f,v)          caf_sem_posix_get (k,f,v)
#define CAF_SEM_DELETE(s)           caf_sem_posix_delete (d)
#define CAF_SEM_EXISTS(s)           caf_sem_posix_exists (s)
#define CAF_SEM_LOCK(s)             caf_sem_posix_lock (s)
#define CAF_SEM_TRYLOCK(s)          caf_sem_posix_trylock (s)
#define CAF_SEM_UNLOCK(s)           caf_sem_posix_unlock (s)

#define CAF_SEM_T                   caf_sem_posix_t

#else /* !CAF_USE_POSIX_SEMAPHORES */
#include <caf/caf_sem_svr4.h>

#define CAF_SEM_NEW(k,n,f)          caf_sem_svr4_new (k,n,f)
#define CAF_SEM_GET(k,n,f)          caf_sem_svr4_get (k,n,f)
#define CAF_SEM_DELETE(s)           caf_sem_svr4_delete (s)
#define CAF_SEM_EXISTS(s)           caf_sem_svr4_exists (s)
#define CAF_SEM_LOCK(s)             caf_sem_svr4_lock (s);
#define CAF_SEM_TRYLOCK(s)          caf_sem_svr4_trylock (s)
#define CAF_SEM_UNLOCK(s)           caf_sem_svr4_unlock (s)

#define CAF_SEM_T                   caf_sem_svr4_t

#endif /* !CAF_USE_POSIX_SEMAPHORES */

/** }@ */
#endif /* !CAF_SEM_H */
/* caf_sem.h ends here */
