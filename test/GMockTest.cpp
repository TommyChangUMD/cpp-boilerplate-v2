#include "gmock/gmock.h"
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

class MockQueue : public QueueInterface {
public:
  MOCK_METHOD0 (dequeue, int());
  MOCK_METHOD1 (enqueue, void(int data));

};

TEST (GMockTests, canAssertTrue) {
  ASSERT_TRUE(true);
}

TEST (GMockTests, canInstantiateDataHolder) {
  MockQueue mockQueueObj;
  DataHoder dataHolder (&mockQueueObj);
}

TEST (GMockTests, canAddData) {
  MockQueue mockQueueObj;
  DataHoder dataHolder (&mockQueueObj);

  EXPECT_CALL (mockQueueObj, enqueue(_));
  // EXPECT_CALL (mockQueueObj, dequeue());

  dataHolder.AddData(1);
}


TEST (GMockTests, canAddAndGetData) {
  MockQueue mockQueueObj;
  DataHoder dataHolder (&mockQueueObj);

  EXPECT_CALL (mockQueueObj, enqueue(1));
  EXPECT_CALL (mockQueueObj, dequeue()).WillOnce(Return(1));

  dataHolder.AddData(1);
  int result = dataHolder.GetData();
  ASSERT_EQ (1, result);
}

