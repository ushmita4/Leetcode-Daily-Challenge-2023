class FoodRatings {
    unordered_map<string, int> foodRatingMap;
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, set<pair<int, string>>> cuisineFoodMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            // Store 'rating' and 'cuisine' of current 'food' in 'foodRatingMap' and 'foodCuisineMap' maps.
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            // Insert the '(-1 * rating, name)' element in current cuisine's set.
            cuisineFoodMap[cuisines[i]].insert({ -ratings[i], foods[i] });
        }
    } 

    void changeRating(string food, int newRating) {
        // Fetch cuisine name for food.
        auto cuisineName = foodCuisineMap[food];

        // Find and delete the element from the respective cuisine's set.
        auto oldElementIterator = cuisineFoodMap[cuisineName].find({ -foodRatingMap[food], food });
        cuisineFoodMap[cuisineName].erase(oldElementIterator);
        foodRatingMap[food] = newRating;
        cuisineFoodMap[cuisineName].insert({ -newRating, food });
    }
    
    string highestRated(string cuisine) {
        auto highestRated = *cuisineFoodMap[cuisine].begin();
        return highestRated.second;
    }
};
