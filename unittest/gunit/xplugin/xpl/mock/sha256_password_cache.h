/*
 * Copyright (c) 2017, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2.0,
 * as published by the Free Software Foundation.
 *
 * This program is also distributed with certain software (including
 * but not limited to OpenSSL) that is licensed under separate terms,
 * as designated in a particular file or component or in included license
 * documentation.  The authors of MySQL hereby grant you an additional
 * permission to link the program and your derivative works with the
 * separately licensed software that they have included with MySQL.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License, version 2.0, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
 */

#ifndef _XPL_SHA256_PASSWORD_CACHE_MOCK_H_
#define _XPL_SHA256_PASSWORD_CACHE_MOCK_H_

#include <string>
#include <utility>

#include <gmock/gmock.h>

#include "plugin/x/ngs/include/ngs/interface/sha256_password_cache_interface.h"
#include "plugin/x/src/cache_based_verification.h"

namespace xpl {
namespace test {

class Mock_sha256_password_cache : public ngs::SHA256_password_cache_interface {
 public:
  MOCK_METHOD3(upsert, bool(const std::string &, const std::string &,
                            const std::string &));
  MOCK_METHOD2(remove, bool(const std::string &, const std::string &));
  MOCK_CONST_METHOD2(get_entry,
                     std::pair<bool, std::string>(const std::string &,
                                                  const std::string &));
  MOCK_CONST_METHOD3(contains, bool(const std::string &, const std::string &,
                                    const std::string &));
  MOCK_CONST_METHOD0(size, std::size_t());
  MOCK_METHOD0(clear, void());
  MOCK_METHOD0(enable, void());
  MOCK_METHOD0(disable, void());
};

class Mock_cache_based_verification : public Cache_based_verification {
 public:
  explicit Mock_cache_based_verification(
      ngs::SHA256_password_cache_interface *cache)
      : Cache_based_verification(cache) {}
  MOCK_CONST_METHOD0(get_salt, const std::string &());
};

}  // namespace test
}  // namespace xpl

#endif  // _XPL_SHA256_PASSWORD_CACHE_MOCK_H_
