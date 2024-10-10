// Copyright 2009-present MongoDB, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <vector>

#include <bsoncxx/document/view.hpp>
#include <bsoncxx/stdx/optional.hpp>
#include <bsoncxx/types.hpp>

#include <mongocxx/uri.hpp>

#include <examples/api/runner.hh>
#include <examples/macros.hh>

namespace {

// [Example]
void example() {
    mongocxx::uri uri{"mongodb://localhost:27017/?appName=example&tls=true&maxPoolSize=10"};

    bsoncxx::document::view options = uri.options();

    EXPECT(options["appname"]);
    EXPECT(options["appname"].get_string().value.compare("example") == 0);

    EXPECT(options["tls"]);
    EXPECT(options["tls"].get_bool().value == true);

    EXPECT(options["maxpoolsize"]);
    EXPECT(options["maxpoolsize"].get_int32().value == 10);
}
// [Example]

}  // namespace

RUNNER_REGISTER_COMPONENT_WITH_INSTANCE() {
    example();
}
