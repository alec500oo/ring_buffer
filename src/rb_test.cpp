/* rb_test.cpp */

#include "doctest.h"
#include "ring_buffer.hpp"

#include <utility>

TEST_CASE("create buffer")
{
    ring_buffer<int, 5> rb;
    CHECK(rb.empty() == true);
    CHECK(rb.size() == 5);
}

TEST_CASE("add items")
{
    ring_buffer<int, 5> rb;
    rb.push(1);
    rb.push(2);
    rb.push(3);
    CHECK(rb.front() == 1);
    rb.pop();
    CHECK(rb.front() == 2);
    rb.pop();
    const auto a = std::as_const(rb).front();

}

TEST_CASE("overwrite")
{
    ring_buffer<int, 3> rb;
    rb.push(1);
    rb.push(2);
    rb.push(3);
    rb.push(4);
    CHECK(rb.front() == 2);
}

TEST_CASE("overwrite and pop")
{
    ring_buffer<int, 3> rb;
    rb.push(1);
    rb.push(2);
    rb.push(3);
    rb.push(4);
    CHECK(rb.front() == 2);
    rb.pop();
    CHECK(rb.front() == 3);
    rb.pop();
    rb.push(5);
}

