class indexNode {
public:
	int weight;
	indexNode* firstOne;
}
makeIndexList()
{
	indexNode* spot;
	int currWeight;
	indexNode weightIndex[10];
	/* Fill in the index array. */
	for (int j = 0;j < 10;) {
		currWeight = ++j;
		weightIndex[j].weight = currWeight;
		spot = find_spot(currWeight);
		if ((spot != head) && (spot.weight != (currWeight)) {
			weightIndex[j].firstOne = NULL;
		}
		else {
			weightIndex[j].firstOne = spot;
		}

	};

