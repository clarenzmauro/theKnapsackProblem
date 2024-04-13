// C: Implement greedy strategy on the knapsack problem in a C program? What on Earth even is "greedy strategy"?!
// ChatGPT: A greedy strategy is a way of solving problems where you make the best choice at each step without considering the bigger picture. It's like being greedy for the immediate benefit without thinking about the consequences later on. It can be useful for some problems where the best choice at each step leads to the overall best solution, but it can also backfire if the best local choices don't add up to the best overall solution.
// C: Okay, okay. I think I get it now, but what is a knapsack problem??
// ChatGPT: The knapsack problem is a classic optimization problem in computer science and mathematics. Imagine you have a knapsack (a backpack) with a limited weight capacity, and you are given a set of items, each with its own weight and value. The goal is to determine the combination of items to include in the knapsack that maximizes the total value while not exceeding the weight capacity of the knapsack. It's like trying to pack your backpack with the most valuable items without making it too heavy to carry. There are different variations of the knapsack problem, each with its own constraints and objectives.
// C: I get it now, so basically, if I would relate it to business I should aim to maximize profits. Right?
// ChatGPT: Exactly! In a business context, you can think of the knapsack problem as trying to maximize your profit while considering constraints like limited resources or budget. Each item you can choose to include in your "knapsack" represents a potential investment or project with its own cost and potential return. By selecting the right combination of investments, you aim to maximize your overall profit within the constraints of your resources or budget.
// C: Right! Now I can program it. Let's see...

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

// needed for swapping values in an array
void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void knapsackGreedy(Item items[], int n, int capacity) {
    // this should calculate the ratio of value to weight for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float) items[i].value / items[i].weight;
    }

    // this should sort the items based on their value-to-weight ratio in non-increasing order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }

    int currentWeight = 0; // Current weight in knapsack
    float finalValue = 0; // Final value of items in knapsack

    // this fills the knapsack
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
            printf("Selected item: Weight = %d, Value = %d\n", items[i].weight, items[i].value); // maximum value!
        } else {
            int remainingCapacity = capacity - currentWeight;
            finalValue += items[i].ratio * remainingCapacity;
            printf("Selected item: Weight = %d, Value = %d (Fraction: %d/%d)\n", items[i].weight, items[i].value, remainingCapacity, items[i].weight);
            break;
        }
    }

    printf("Total value in knapsack: %.2f\n", finalValue);
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsackGreedy(items, n, capacity);

    return 0;
}
