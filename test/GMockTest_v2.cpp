#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>

using testing::_;
using testing::Return;

// Google Mock exercise:
// ref: https://www.linkedin.com/learning/test-driven-development-in-c-plus-plus
//
// Write an DataHolder Interface that 
// - [X] Can instantiate dataHolder
// - [X] Can add data
// - [X] Can add data and get data


class QueueInterface {
public:
  virtual void enqueue (int data) = 0;
  virtual int dequeue () = 0;
};


//==================================
// DataHoder
//==================================

class DataHoder {
public:
  DataHoder (QueueInterface *queueI) : // dependency injection
    queue (queueI) {
  };

  void AddData (int data) {
    queue->enqueue(data);
  }

  int GetData () {
    return queue->dequeue();
  }

protected:
  QueueInterface *queue;
             
};


//==================================
// Mock for Queue
//==================================

class MockQueue : public QueueInterface {
public:
  MOCK_METHOD0 (dequeue, int());
  MOCK_METHOD1 (enqueue, void(int data));
};


//==================================
// Test Fixture
//==================================


class GMockTests : public testing::Test {
public:
  GMockTests () :
    dataHolder (&mockQueueObj) {
  };
  
protected:
  void SetUp() override {
    std::cout << "Calling Fixture SetUp\n";
  };
  
  void TearDown () override {
    std::cout << "Calling Fixture TearDown\n";
  };
  
  MockQueue mockQueueObj;
  DataHoder dataHolder;
};


//==================================
// Unit Tests
//==================================

TEST_F (GMockTests, canAddData_v2) {
  // Setup Mock behavior
  EXPECT_CALL (mockQueueObj, enqueue(_));

  // Run the test
  dataHolder.AddData(1);
}

TEST_F (GMockTests, canAddAndGetData_v2) {

  // Setup Mock behavior
  EXPECT_CALL (mockQueueObj, enqueue(1));
  EXPECT_CALL (mockQueueObj, dequeue()).WillOnce(Return(1));

  // Run the test
  dataHolder.AddData(1);
  int result = dataHolder.GetData();
  ASSERT_EQ (1, result);
}

