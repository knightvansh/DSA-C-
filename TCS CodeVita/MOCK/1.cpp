

// Interview Test
// Problem Description

// Rahil is a freelancer currently working as an interviewer for XYZ Company. He designs and conducts interviews by presenting candidates with carefully curated questions, often inspired by real-life scenarios. Through this approach, he effectively assesses their problem-solving and implementation skills.

// Inspired by the LED clock display at the railway station, Rahil came up with an interesting question! Here's how it works:

// The candidate is given a time from the LED display.
// Their task is to find the closest possible time to the given time, following these rules:
// The candidate sets the given time on an analog clock.
// Both the hour and minute hands can be moved in any direction.
// The hour hand can only point to whole hour positions (1 to 12) and cannot be set between them.
// The minute hand can point to any of the 60-minute marks.
// Moving the hour hand costs X units per minute and moving the minute hand costs Y units per minute. Refer to examples for better understanding.
// The closest time is defined as the one that requires the least total cost to move the clock hands from the initial time and can be formed by toggling just one LED segment.
// If no such time can be formed, print "No closest valid time possible".
// Constraints

// The initial time will always be a valid time in 12-hour format.
// 1 <= X, Y <= 100
// Input

// The first line contains a string representing the initial time in the format HH:MM.

// The second line contains two space-separated integers, X and Y, representing the cost per minute for moving the hour and minute hands, respectively.

// Output

// Print the closest time possible else print "No closest valid time possible"

// Time Limit (secs)

// 1

// Examples

// Example 1

// Input

// 02:38

// 2 5

// Output

// 02:39

// Explanation

// Given time is displayed below in LED display format.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@66bfd864:image1.png

// By toggling off a single LED in 8, you can change it to 9, resulting in the time 02:39 at a lower cost of 5.

// Example 2

// Input

// 02:42

// 10 8

// Output

// No closest valid time possible

// Explanation

// It's not possible to form a valid time on the LED display by toggling just one segment. Therefore, print "No closest valid time possible."






Arrange Track
Problem Description
You have been assigned the task of laying railway tracks between two stations. Because the plan is too large for a single sheet, it is divided across several sheets.

Your job is to connect two stations by laying down tracks. The plan is a square grid of size N x N, split into smaller square sheets of size M x M. Both the full plan and each sheet are always square.

After drawing the track positions, you arranged the sheets to form the complete plan. However, the sheets got shuffled, and some were rotated. Even the sheets containing the source (S) and destination (D) stations might have changed orientation.

For example, a 6 x 6 plan might look like this:

LLLLLL

LSTTTL

LLLLTL

LLLLTL

LLLLDL

LLLLLL

Here, L represents Land, S and D represent stops between which the Track has to be laid, and T represents the Track.

If divided into 3 x 3 sheets, the plan would be split as shown in the original document.
LLL LLL LLL LTL

LST TTL LLL LDL

LLL LTL LLL LLL

Since the map is unarranged, the entire plan may be reconstructed as follows:

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@22ee2d0:image1.png

Your task is to rearrange the individual sheets to reconstruct the complete plan, ensuring a continuous track between S and D. The sheet containing S will always be placed in the top-left corner, and the sheet with D will always be in the bottom-right corner, in the same position as in the input. After rearranging, the distance between S and D should be the shortest possible.

Important: The track cannot run over the edges of the individual sheets. Tracks are single-lane and do not have branches. Extra tracks may exist but are not part of the path between S and D.

Hence, the following is not valid:
LLL
TLL
TTL

Rearrange the map and return the shortest distance along the track between S and D. D is included in the distance calculation.

Constraints
6 <= N <= 25

3 <= M <= 5

N/M will always be integer.

Input
The first line contains two space-separated integers representing N and M.
The next N lines contain N space-separated characters, either L, T, S, or D, representing the misarranged plan.

Output
Print a single integer representing the shortest distance along the track between S and D (including the destination in the count)

Time Limit (secs)
1

Examples
Example 1

Input

6 3

LLLLLL

LSTLLL

LLLLLL

LLLLTL

TTLLDL

LTLLLL

Output

6

Explanation

The example is the same as the one explained in the description. The shortest distance between S and D after arrangement will be 6.

Example 2

Input

6 3

LLLLLL

LSTLLL

LLLLLL

LLLLTL

LTTLDL

LTLLLL

Output

6

Explanation

From the input, the full plan is 6 x 6, and the individual sheet is 3 x 3. The individual sheets are:
LLL LLL LLL LTL

LST LLL LTT LDL

LLL LLL LTL LLL

Here, sheets are represented by their indices in order 1 to 4. The sheets containing S and D will be at (0,0) and (1,1) respectively. If sheet 2 is rotated and placed at (0,1), it won't connect to the D. Therefore, sheet 3 is rotated and placed at (0,1) to ensure that D in (1,1) is connected. The complete rearranged plan is:

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@22ee2d0:image2.png

The shortest distance is 6. Hence, print the same.








3


StrangeString
Problem Description
Detective Lara enters a haunted bungalow and finds a puzzle: a strange string is written on a door. To unlock a hidden room, she must create a new string using wooden pieces, each with its own sequence of letters and cost. She can use any number of pieces (with unlimited supply) and arrange them in any order. The new string formed, must contain the strange string as a subsequence, and the goal is to minimize the total cost.

Lara first thinks she can rearrange the letters within each wooden piece, which helps her getting a minimum cost (X). Later, she learns that rearranging letters within a piece is not allowed — she must use the letters in the same order they appear on the wooden piece. Now, she wants to know: How much more will it cost to follow the correct rule?
Constraints
1 <= N <= 100

1 <= length of each string on wooden pieces <= 20

1 <= length of strange string <= 1000

1 <= cost of each string on the wooden piece <= 100

All the substrings and the strange string consist of lowercase alphabets only.

Input
First line: The strange string on the door.

Second line: Integer N (number of wooden pieces).

Third line: N space-separated strings (the wooden pieces).

Fourth line: N space-separated integers (costs of each piece).

Output
Print a single integer: the additional cost Lara must pay when rearrangement is not allowed.

Time Limit (secs)
1

Examples
Example 1

Input

gowiththeflow

8

cat and goat wins the game of life

2 5 1 4 8 3 1 11

Output

1

Explanation

The strange string written on the door is "gowiththeflow", and Lara is given eight types of wooden pieces, each with its own string and cost.

At first, she mistakenly believes she can rearrange the letters within each wooden piece. Based on this, she selects the pieces: goat (1), wins (4), the (8) twice, life (11), of (1), and wins (4), making the minimum total cost 37. She uses these pieces, rearranging the letters inside them to form a new string where "gowiththeflow" appears as a subsequence.

However, rearranging letters within a piece is not allowed. When Lara re-evaluates the problem following the correct rule - that the letters on each wooden piece must remain in their original order, she finds that she can still form a valid string containing "gowiththeflow" as a subsequence by using goat (1), wins (4), the (8) twice, of (1), life (11), of (1), and wins (4). This brings the minimum total cost to 38. The extra piece "of" is needed to maintain the correct letter order and still form the required subsequence. Therefore, Lara needs to pay 1 more than her original plan, and the final answer is 1.

Example 2

Input

abcdefg

5

cad bed fan gate bug

7 9 4 11 2

Output

0

Explanation

The strange string on the door is "abcdefg", and Lara is given 5 types of wooden pieces: "cad", "bed", "fan", "gate", and "bug", with respective costs of 7, 9, 4, 11, and 2. First, Lara assumes she can rearrange the letters inside each wooden piece to help form the target string more easily. Under this incorrect assumption, she selects the pieces fan (4), bug (2), cad (7), bed (9), fan (4), bug (2). By rearranging letters, she can extract the necessary characters to form the subsequence "abcdefg", and the total cost comes out to 28.

However, since rearranging the letters inside a piece is not allowed, she must now find a valid way to form a string where "abcdefg" appears as a subsequence, but since "abcdefg" also appears as a subsequence when all the above selected strings are concatenated in the same order i.e.., without interchanging of the letters in each string, so there is no change in cost, hence print 0.