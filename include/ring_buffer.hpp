/* ring_buffer.hpp */
/** General template ring buffer for storing a fixed amount of data. */

#pragma once

#include <array>
#include <cstddef>

template <class T, std::size_t N>
class ring_buffer {
public:
    using container_type = std::array<T, N>;
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
 
    /** Get the size of the buffer */
    constexpr size_type size() const noexcept { return N; }

    /** Check if the buffer is empty */
    constexpr bool empty() const noexcept { return empty_(); }

    reference front() {	return buf_[read_idx_]; }

    const_reference front() const { return buf_[read_idx_]; }

    void pop()
    {
	if (!empty_())
	    adv_read_();
    }

    void push(const value_type& v)
    {
	buf_[write_idx_] = v;
	adv_write_();
    }

    void push(value_type&& v) { push(v); }
private:
    std::array<T, N> buf_;
    
    size_type read_idx_ = 0;
    size_type write_idx_ = 0;

    bool full_ = false;

    /** Advance the write pointer with a special consideration for the full condition */
    void adv_write_()
    {
	if (full_)
	    ++read_idx_ %= buf_.size();

	++write_idx_ %= buf_.size();
	full_ = write_idx_ == read_idx_;
    }

    void adv_read_()
    {
	full_ = false;
	++read_idx_ %= buf_.size();
    }

    bool empty_() const noexcept { return write_idx_ == read_idx_ && !full_; }
};

