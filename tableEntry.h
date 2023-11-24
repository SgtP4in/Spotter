#pragma once
class tableEntry {
public:
	tableEntry(double row, double col, int cont) {
		rowKey = row;
		colKey = col;
		content = cont;

	}

	double rowKey;
	double colKey;
	int content;

};