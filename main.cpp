//Main.cpp
//Choudhry, Zane
//Zchoudhry

#include <iostream>
#include <sstream>
#include <string>
#include "video.h"

using namespace std;

// Create a video object from an input
Video *readVideo()
{
	string title;

	if (!getline(cin, title))
		return NULL;

	string url;
	getline(cin, url);

	string comment;
	getline(cin, comment);

	string line;
	getline(cin, line);
	double length;
	stringstream lengthStream(line);
	lengthStream >> length;

	getline(cin, line);
	int rating;
	stringstream ratingStream(line);
	ratingStream >> rating;

	return new Video(title, url, comment, length, rating);
}

// Swap locations of 2 videos in the list
void swap(Video **videos, int i, int j)
{
	Video *temp = videos[i];
	videos[i] = videos[j];
	videos[j] = temp;
}

// Sort the videos from highest to lowest rating using bubble sort
void sortByRating(Video **videos, int numVideos)
{
	for (int i = 0; i < numVideos - 1; i++)
		for (int j = 0; j < numVideos - i - 1; j++)
			if (videos[j]->getRating() < videos[j + 1]->getRating())
				swap(videos, j, j + 1);
}

// Sort the videos by length from shortest to longest using bubble sort
void sortByLength(Video **videos, int numVideos)
{
	for (int i = 0; i < numVideos - 1; i++)
		for (int j = 0; j < numVideos - i - 1; j++)
			if (videos[j]->getLength() > videos[j + 1]->getLength())
				swap(videos, j, j + 1);
}

// Sort the videos by title, alphabetically using bubble sort
void sortByTitle(Video **videos, int numVideos)
{
	for (int i = 0; i < numVideos - 1; i++)
		for (int j = 0; j < numVideos - i - 1; j++)
			if (videos[j]->getTitle() > videos[j + 1]->getTitle())
				swap(videos, j, j + 1);
}


int main()
{
	const int MAX_VIDEOS = 100;

	Video **videos = new Video*[MAX_VIDEOS];
	int numVideos = 0;

	

	// First line is the sorting criteria
	string sortCriteria;
    cin >> sortCriteria;
    cin.ignore();

	if (sortCriteria != "rating" && sortCriteria != "length" && sortCriteria != "title")
	{
		cerr << sortCriteria << " is not a legal sorting method, giving up." << endl;
		return 1;
	}

	// The rest of the lines are the videos
	Video *video = readVideo();

	while (video != NULL)
	{
    
        if(numVideos >= MAX_VIDEOS){
            cerr << "Too many videos, giving up." << endl;
            return 1;
        }
        
		videos[numVideos] = video;
		video = readVideo();
        numVideos++;
	}

	// Perform sorting beased on the user inputs choice
	if (sortCriteria == "rating")
		sortByRating(videos, numVideos);
	else if (sortCriteria == "length")
		sortByLength(videos, numVideos);
	else if (sortCriteria == "title")
		sortByTitle(videos, numVideos);

	// Print out the sorted videos based on the sort criteria
	for (int i = 0; i < numVideos; i++)
	{
		videos[i]->print();
        cout << endl;
	}

	// Delete all video objects (Deallocate)
    for (int i = 0; i < numVideos; i++)
		delete videos[i];

	delete[] videos;
	return 0;
}
