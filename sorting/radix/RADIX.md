# Radix Sort Explained (For Non-Tech & Tech People)

---

## 🧑‍🏫 Simple Explanation (Non-Technical)

Radix Sort is like **sorting numbers by their digits**.

Imagine you have a stack of cards with numbers on them:

- First, you sort the cards **by the rightmost digit** (ones place).
- Then sort the cards by the **next digit to the left** (tens place).
- Repeat for hundreds, thousands, etc., until the **most significant digit**.

By the end, the numbers are perfectly sorted, without ever comparing the numbers directly.

---

## 📦 Real-Life Examples

1. **Sorting a deck of numbered cards**:

   - First by ones digit, then tens, then hundreds.

2. **Organizing files by IDs**:

   - Employee ID: 1234 → sort by last digit first, then the next, etc.

3. **Sorting phone numbers**:
   - First by last digit, then second-to-last, up to the first digit.

---

## 🔢 Step-by-Step Example (Numbers)

We want to sort:

### Step 1: Sort by 1’s place (least significant digit)

- Ones digits: [0, 5, 5, 0, 2, 4, 2, 6]
- Array after sorting by ones:

### Step 2: Sort by 10’s place

- Tens digits: [7, 9, 0, 0, 2, 4, 7, 6]
- Array after sorting by tens:

### Step 3: Sort by 100’s place (most significant digit)

- Hundreds digits: [8, 0, 0, 0, 0, 1, 0, 0]
- Array after sorting by hundreds:

✅ Final Sorted Array = `[2, 24, 45, 66, 75, 90, 170, 802]`

---

## ⏱ Time Complexity

- **Best Case:** `O(nk)`
- **Average Case:** `O(nk)`
- **Worst Case:** `O(nk)`

Where:

- `n` = number of elements
- `k` = number of digits in the maximum number

> Radix Sort’s time complexity is independent of comparisons.

---

## 💾 Space Complexity

- **O(n + k)** (uses counting sort for each digit, needs temporary storage)

---

## ✅ Pros

- Very fast for numbers with **small number of digits**.
- Non-comparative sort → avoids expensive comparisons.
- Stable sort (preserves relative order of equal elements).

## ❌ Cons

- Only works for integers or fixed-length strings.
- Needs extra memory for temporary arrays.
- Not suitable for very large numbers with many digits (k becomes large).

---

## 🍎 Real-Life Analogy

- **Sorting mail by zip code**:
  - First by last digit of zip, then next digit, until first digit.
- **Sorting tickets by seat number**:
  - Start with units digit → tens → hundreds → final order.

---
