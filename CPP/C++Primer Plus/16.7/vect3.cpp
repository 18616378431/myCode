//16.7 vector for_each,random_shuffle,sort
#include <iostream>
#include <string>
#include <vector>//vector.h
#include <algorithm>//algo.h for old complier

struct Review{
	std::string title;
	int rating;
};

bool operator< (const Review & r1,const Review & r2);
bool WorseThan(const Review & r1,const Review & r2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
	using namespace std;

	vector<Review> books;
	Review temp;
	while(FillReview(temp))
		books.push_back(temp);
	cout << "Thank you.You entered the following "
		<< books.size() << " ratings:\n"
		<< "Rating\tBook\n";
	for_each(books.begin(),books.end(),ShowReview);
	sort(books.begin(),books.end());
	cout << "Sorted by title:\nRating\tBook\n";
	for_each(books.begin(),books.end(),ShowReview);

	sort(books.begin(),books.end(),WorseThan);
	cout << "Sorted by rating:\nRating\tBook\n";
	for_each(books.begin(),books.end(),ShowReview);

	random_shuffle(books.begin(),books.end());
	cout << "After shuffling:\nRating\tBook\n";
	for_each(books.begin(),books.end(),ShowReview);
	
	cout << "Bye.\n";

	return 0;
}
bool operator< (const Review & r1,const Review & r2)
{
	if(r1.title < r2.title)
		return true;
	else if(r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}
bool WorseThan(const Review & r1,const Review & r2)
{
	if(r1.rating < r2.rating)
		return true;
	else
		return false;
}
bool FillReview(Review & rr)
{
	std::cout << "Enter book title(quit to quit):";
	std::getline(std::cin,rr.title);
	if(rr.title == "quit")
		return false;
	std::cout << "Enter book rating:";
	std::cin >> rr.rating;
	if(!std::cin)
		return false;
	std::cin.get();
	return true;
}
void ShowReview(const Review & rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}