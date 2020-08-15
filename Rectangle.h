//
//  Rectangle.h
//
//  A module to represent an area in 2D space.
//

#pragma once

//  Class Invarint:
//    <1> row_count < 1
//    <2> column_count < 1
//

class Rectangle
{
public:
	Rectangle();
	Rectangle(int min_row1, int min_column1, 
		      int row_count1, int column_count1);
	int getMinRow() const;
	int getMinColumn() const;
	int getMaxRow() const;
	int getMaxColumn() const;
	int getRowCount() const;
	int getColumnCount() const;
	bool isIntersection(const Rectangle& other) const;
	void setPosition(int new_min_row, int new_min_column);
	void addPosition(int delta_row, int delta_column);

private:
	bool invariant()const;

private:
	int min_row;
	int min_column;
	int row_count;
	int column_count;
};
