A Binary Search Tree is a type of binary tree where every node in the left subtree contains a
value less than the that of the root, and every node in the right subtree contains one that is
greater. This property can be applied to every node.

The traversal algorithm used will be the postorder traversal, with a theoretical time complexity
of O(n) in the best, average, and worst-case scenarios. This is because each node is visited
only once in each case. In this project, I will compare the average time taken to perform postorder 
traversal after some tries with the theoretical time complexity function, which is linear in
all these three cases. Since O(n) is a linear function of the format (an+b) where a and b are two
constants, I will consider the linear trendline from the graph as the O(n) theoretical graph. Both
theoretical and experimental graphs will be in respect to the data sizes applied to both theoretical
and experimental time complexities.

The C++ code included in the zip file (main.cpp) creates a binary search tree of size newSize.
newSize can be programmed to be any size, but for this report I chose values from 5000 to
50000, incremented by 5000. I have left a few options on how to fill in the tree. The first one of
fills it in randomly, resulting in an average time complexity, the second one fills it in by
increasing order, resulting in the worst-case time complexity, and the third one fills it in with a
special function to make the tree balanced, resulting in the best-case time complexity.

The results for the worst and best cases were reasonable since the linear trendline was somewhat
similar to the experimental graph. The average case, however, appeared to be exponential. This
was clearly unexpected and could have been caused by a multitude of factors like the dataset
used, hardware or compiler optimization, or certain details within the written code.

To test this code, set newSize to the value that you wish or modify the code using the comments 
provided to obtain user input. Afterwards, modify the code once again to choose a mode for node 
insertion in the binary search tree. I have formatted the code this way for more efficiency, as this 
was the way in which I used it for my time complexity experiment.
