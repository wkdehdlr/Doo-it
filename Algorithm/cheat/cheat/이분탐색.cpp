//최댓값
while (low < high) {
	mid = (low + high + 1) / 2;
	if (ok) {
		low = mid;
	}
	else {
		high = mid - 1;
	}
}


//최솟값
while (low < high) {
	mid = (low + high) / 2;
	if (ok) {
		high = mid;
	}
	else {
		low = mid + 1;
	}
}
return low;