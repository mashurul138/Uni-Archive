1. Polycarp plays a well-known computer game (we won't mention its name). In this game, he can craft tools of two types — shovels and swords. To craft a shovel, Polycarp spends two sticks and one diamond; to craft a sword, Polycarp spends two diamonds and one stick. Each tool can be sold for exactly one dollar. How many dollars can Polycarp earn, if he has a sticks and b diamonds?

2. Check if it is possible to survive on an Island. Jarif got stuck on an island. There is only one shop on this island, and it is open on all days of the week except for Sunday. Consider following constraints: 
N – The maximum unit of food you can buy each day. 
S – Number of days you are required to survive. 
M – Unit of food required each day to survive. 
Currently, it’s Monday, and he needs to survive for the next ‘S’ days. 
Find the minimum number of days on which you need to buy food from the shop so that he can survive the next ‘S’ days or determine that it isn’t possible to survive. 
Example 1: 
Input: S = 10, N = 16, M = 2 
Output: 2 

3. Following items are available in a grocery shop: 
➢ 12 kilogram rice grain which costs 840 taka 
➢ 10 kilogram salt which costs 870 taka 
➢ 8 kilogram saffron powder which costs 2000 taka and 
➢ 5 kilogram sugar which costs 500 taka 
A group of thieves (Thief 1, Thief 2, … Thief M) have come to steal from that shop, each with a knapsack of capacity 9 kg. The thieves are entering in serial, Thief 2 enters after Thief 1 is done with stealing, Thief 3 enters after Thief 2 is done with stealing and so on. Since each thief wants to maximize his/her profit, how many thieves will be needed in the group to empty the grocery shop and what are the items that each of those thieves carry? Also print each thief’s profit.

4. You are given the arrival and the departure times of eight trains for a railway platform, and each one is in the format: [arrival time, departure time). Only one train can use the platform at a time. There must be at least 1 unit time gap between 2 consecutive trains. Suppose that you have got the following train-use requests for the next day. 
{ [8, 12), [6, 9), [11, 14), [2, 7), [1, 7), [12, 20), [7, 12) , [13, 19) } 
Find the maximum number of trains that can use the platform without any collision by using earliest departure time. 	

5. You are given an array 𝐴 of length 𝑁. In one move, select an integer 𝑋 and do one of the following operations:
Choose one index 𝑖(1<=𝑖<=𝑁) such that |𝐴[𝑖]−𝑋|<=1 and remove 𝐴[𝑖].
Choose two indices 𝑖 and 𝑗(1<=𝑖,𝑗<=𝑁,𝑖≠𝑗) such that |𝐴[𝑖]−𝑋|<=1 and |𝐴[𝑗]−𝑋|<=1 and remove 𝐴[𝑖] and 𝐴[𝑗] from the array.
Find the minimum number of moves required to make the array empty.

Sample input:
A[]={1 3 5 9} output: 3
you can choose X = 4, then remove A[1] and A[2]
you can choose X = 1, then remove A[0]
you can choose X = 9, then remove A[3]

6. Given the arrival and the departure times (in minutes) of 8 trains for a railway platform, find out the maximum number of trains that can use that platform without any collision, using a greedy algorithm. There must exist at least 10 minutes of safety break between the departure of one train and arrival of the next one.
[1000, 1030], [840, 1030], [850, 1040], [1700, 2000], [800, 835], [1300, 1800], [1500, 1650], [1200, 1380]
You must print the selected trains.

