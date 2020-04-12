#include "Linked_list.h"

utec::first::linked_list_t::linked_list_t(const linked_list_t& other)
{
	if(other.head_==nullptr)
	{
		head_ = nullptr;
	}
	else
	{
		auto actual = other.head_;

		while (actual->next_ != nullptr)
		{
			push_back(actual->value_);
			actual = actual->next_;
		}
		push_back(actual->value_);
	}
	return;
}

utec::linked_list_t& utec::first::linked_list_t::operator=(const linked_list_t& other)
{
	head_ = other.head_;
	tail_ = other.tail_;
	size_ = other.size_;
	linked_list_t(other);
	return *this;
}

utec::first::linked_list_t::linked_list_t(linked_list_t&& other) noexcept
{
	return;
}

utec::linked_list_t& utec::first::linked_list_t::operator=(linked_list_t&& other) noexcept
{
	// TODO: insertar una instrucción return aquí
	return *this;
}

// Destroyer

utec::first::linked_list_t::~linked_list_t()
{
	while (size_ != 0)
	{
		pop_front();
		size_--;
	}
}

//Agregar 

void utec::first::linked_list_t::push_front(int value)
{
	head_ = new node_t{ value,head_};

	if(tail_ == nullptr)
	{
		tail_ = head_;
	}
	size_++;
}

void utec::first::linked_list_t::push_back(int value)
{
	auto temp_ = new node_t{ value, nullptr };
	auto actual = head_;

	if (head_ == nullptr)
	{
		head_ = temp_;
	}
	else
	{
		while (actual->next_ != nullptr)
		{
			actual = actual->next_;
		}
		actual->next_ = temp_;
	}
	size_++;
}

void utec::first::linked_list_t::insert(size_t index, int value)
{
	node_t* temp_ = nullptr;

	if (index == 0)
	{
		push_front(value);
	}
	else
	{
		if (index < size_)
		{
			temp_ = new node_t{};
			temp_->value_ = value;
			
			auto actual = head_;
			
			while (index--)
			{
				actual = actual->next_;
			}
			
			auto P = actual->next_;
			actual->next_ = temp_;
			temp_->next_ = P;

		}
		else
		{
			push_back(value);
		}
	}
	size_++;
}

// Borrar 

void utec::first::linked_list_t::pop_front()
{
	if (head_ == tail_)
	{
		delete head_;
		head_ = tail_ = nullptr;
		size_ = 0;
	}
	else
	{
		auto next = head_->next_;
		delete head_;
		head_ = next;
		size_ -- ;
	}
}

void utec::first::linked_list_t::pop_back()
{
	if (head_ == tail_)
	{
		delete head_;
		head_ = tail_ = nullptr;
		size_ = 0;
	}
	else
	{
		delete tail_;
		size_--;
	}
}

void utec::first::linked_list_t::erase(size_t index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		if (index < size_)
		{
			auto temp_ = head_;
			auto actual = head_;

			while (index--)
			{
				actual = actual->next_;
				if (index == 1)
				{
				    temp_ = actual;
				}
			}

			auto P = actual->next_;
			temp_->next_ = P ;
		}
		else
		{
			pop_back();
		}
	}
	size_++;
}

int& utec::first::linked_list_t::item(size_t index)
{
	auto actual = head_;
	while (index--)
	{
		actual = actual -> next_;
	}
	return actual->value_;
}

const int& utec::first::linked_list_t::item(size_t index) const
{
	auto actual = head_;
	while (index--)
	{
		actual = actual->next_;
	}
	return actual->value_;
}

size_t utec::first::linked_list_t::size() const
{
	return size_;
}


