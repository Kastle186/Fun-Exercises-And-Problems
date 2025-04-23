// Name: 207. Course Schedule
// Topics: Depth-First Search, Breadth-First Search, Graph, Topological Sort
// Companies:
// - Yelp
// - Zenefits
// - Anduril
// - Coupang
// - Karat
// - ByteDance
// - VMware
// - Docusign
// - Nutanix
// - Flipkart
// - eBay
// - Visa
// - Snap
// - Snowflake
// - Oracle
// - Agoda
// - Walmart Labs
// - Nvidia
// - Intuit
// - Citadel

#include <iostream>
#include <queue>
#include <vector>

bool can_finish(int, std::vector<std::vector<int>>&);
std::vector<std::vector<int>> make_adjlist(int, std::vector<std::vector<int>>&);
std::vector<int> calculate_inbounds(int, std::vector<std::vector<int>>&);

int main(void)
{
    std::vector<std::vector<int>> schedule_1 = {{1, 0}};
    std::vector<std::vector<int>> schedule_2 = {{1, 0}, {0, 1}};

    std::cout << "207. Course Schedule" << std::endl;
    std::cout << can_finish(2, schedule_1) << std::endl;
    std::cout << can_finish(2, schedule_2) << std::endl;

    return 0;
}

bool can_finish(int num_courses, std::vector<std::vector<int>>& prerequisites)
{
    // First things first. We need a graph representation of these prerequisites,
    // (nodes), so we'll begin by building an adjacency list from their given
    // pairs (edges).
    std::vector<std::vector<int>> courses_adjlist =
        make_adjlist(num_courses, prerequisites);

    // Then, we have to know which courses can be taken right away to begin
    // processing them.
    std::vector<int> inbounds =
        calculate_inbounds(num_courses, courses_adjlist);

    std::queue<int> courses_queue;
    int applicable = 0;

    // Populate our queue with the courses we can take right now (i.e. are not
    // dependent on other courses).
    for (int i = 0; i < num_courses; i++)
    {
        if (inbounds[i] == 0)
            courses_queue.push(i);
    }

    // As we go eliminating dependency-less courses, the number of dependencies
    // of those they pointed to will go decreasing, which will gradually make
    // them dependency-less as well, and therefore ready to process. Repeat until
    // we've finished processing all we can.

    while (!courses_queue.empty())
    {
        int c = courses_queue.front();
        courses_queue.pop();
        applicable++;

        // Update each of the courses that depended on the one we just processed,
        // and add them to the queue if they are ready.
        for (int dep : courses_adjlist[c])
        {
            if (--inbounds[dep] == 0)
                courses_queue.push(dep);
        }
    }

    // If we processed all of the courses, then it can be finished (i.e. their
    // dependency graph has no cycles).

    return applicable == num_courses;
}

std::vector<std::vector<int>> make_adjlist(int nodes, std::vector<std::vector<int>>& edges)
{
    std::vector<std::vector<int>> adj_list(nodes);

    // In this problem, the edges are represented as "to reach [0], you must
    // pass through [1]", rather than the classic "[0] gets you to [1]".
 
    for (std::vector<int> edge : edges)
        adj_list[edge[1]].push_back(edge[0]);

    return adj_list;
}

std::vector<int> calculate_inbounds(int nodes, std::vector<std::vector<int>>& adj_list)
{
    std::vector<int> inbounds(nodes, 0);

    for (std::vector<int> outbounds : adj_list)
    {
        for (int target : outbounds)
            inbounds[target]++;
    }

    return inbounds;
}
