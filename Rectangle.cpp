#include <iostream>
#include <cassert>

#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle()
{
	min_row = 0;
	min_column = 0;
	row_count = 1;
	column_count = 1;

	assert(invariant());
}

Rectangle::Rectangle(int min_row1, int min_column1, int row_count1, int column_count1)
{
	min_row = min_row1;
	min_column = min_column1;
	row_count = row_count1;
	column_count = column_count1;

	assert(invariant());
}

int Rectangle::getMinRow() const
{
	assert(invariant());

	return min_row;
}

int Rectangle::getMinColumn() const
{
	assert(invariant());

	return min_column;
}

int Rectangle::getMaxRow() const
{
	assert(invariant());

	return min_row + row_count - 1;
}

int Rectangle::getMaxColumn() const
{
	assert(invariant());

	return min_column + column_count - 1;
}

int Rectangle::getRowCount() const
{
	assert(invariant());

	return row_count;
}

int Rectangle::getColumnCount() const
{
	assert(invariant());

	return column_count;
}

bool Rectangle::isIntersection(const Rectangle& other) const
{
	assert(invariant());

	if (getMaxRow() < other.getMinRow())
		return false;
	if (other.getMaxRow() < getMinRow())
		return false;
	if (getMaxColumn() < other.getMinColumn())
		return false;
	if (other.getMaxColumn() < getMinColumn())
		return false;

	return true;
}

void Rectangle::setPosition(int new_min_row, int new_min_column)
{
	assert(invariant());

	min_row = new_min_row;
	min_column = new_min_column;

	assert(invariant());
}

void Rectangle::addPosition(int delta_row, int delta_column)
{
	assert(invariant());

	min_row += delta_row;
	min_column += delta_column;

	assert(invariant());
}

bool Rectangle::invariant() const
{
	if (row_count < 1)
	{
		return false;
	}
	if (column_count < 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}