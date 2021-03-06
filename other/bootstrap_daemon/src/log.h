/*
 * Tox DHT bootstrap daemon.
 * Logging utility with support of multiple logging backends.
 */

/*
 * Copyright © 2016-2018 The TokTok team.
 * Copyright © 2015-2016 Tox project.
 *
 * This file is part of Tox, the free peer to peer instant messenger.
 *
 * Tox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Tox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Tox.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LOG_H
#define LOG_H

#include <stdbool.h>

#include "../../../toxcore/ccompat.h"

typedef enum LOG_BACKEND {
    LOG_BACKEND_STDOUT,
    LOG_BACKEND_SYSLOG
} LOG_BACKEND;

typedef enum LOG_LEVEL {
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
} LOG_LEVEL;

/**
 * Initializes logger.
 * @param backend Specifies which backend to use.
 * @return true on success, false if log is already opened.
 */
bool log_open(LOG_BACKEND backend);

/**
 * Releases all used resources by the logger.
 * @return true on success, false if log is already closed.
 */
bool log_close(void);

/**
 * Writes a message to the log.
 * @param level Log level to use.
 * @param format printf-like format string.
 * @param ... Zero or more arguments, similar to printf function.
 * @return true on success, false if log is closed.
 */
bool log_write(LOG_LEVEL level, const char *format, ...) GNU_PRINTF(2, 3);


#endif // LOG_H
