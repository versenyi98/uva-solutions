#### Greedy

For each island calculate the left most and the right most point where a radar would reach the island.   
Sort this points. Put a radar in the right most point of the first island. If the next island's left most point is lesser or equal to this point, the next island could be covered with this radar. If the next islands right most point is lesser than the original islands right most point, the radar should be in the new islands right most point