#pragma once

#include "envoy/runtime/runtime.h"

namespace Runtime {

class MockRandomGenerator : public RandomGenerator {
public:
  MOCK_METHOD0(random, uint64_t());
  MOCK_METHOD0(uuid, std::string());
};

class MockSnapshot : public Snapshot {
public:
  MockSnapshot();
  ~MockSnapshot();

  MOCK_CONST_METHOD2(featureEnabled, bool(const std::string& key, uint64_t default_value));
  MOCK_CONST_METHOD3(featureEnabled,
                     bool(const std::string& key, uint64_t default_value, uint64_t random_value));
  MOCK_CONST_METHOD4(featureEnabled, bool(const std::string& key, uint64_t default_value,
                                          uint64_t random_value, uint16_t num_buckets));
  MOCK_CONST_METHOD1(get, const std::string&(const std::string& key));
  MOCK_CONST_METHOD2(getInteger, uint64_t(const std::string& key, uint64_t default_value));
};

class MockLoader : public Loader {
public:
  MockLoader();
  ~MockLoader();

  MOCK_METHOD0(snapshot, Snapshot&());

  testing::NiceMock<MockSnapshot> snapshot_;
};

} // Runtime
