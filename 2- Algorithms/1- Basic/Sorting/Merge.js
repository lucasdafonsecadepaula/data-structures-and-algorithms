function mergeSort(arr) {
  if (arr.length <= 1) {
      return arr;
  }

  // Split the array into two halves
  const mid = Math.floor(arr.length / 2);
  const left = arr.slice(0, mid);
  const right = arr.slice(mid);

  // Recursively sort the left and right halves
  return merge(mergeSort(left), mergeSort(right));
}

function merge(left, right) {
  let result = [];
  let leftIndex = 0;
  let rightIndex = 0;

  // Merge the two sorted halves
  while (leftIndex < left.length && rightIndex < right.length) {
      if (left[leftIndex] < right[rightIndex]) {
          result.push(left[leftIndex]);
          leftIndex++;
      } else {
          result.push(right[rightIndex]);
          rightIndex++;
      }
  }

  // Concatenate any remaining elements
  return result.concat(left.slice(leftIndex)).concat(right.slice(rightIndex));
}

const array = [38, 27, 43, 3, 9, 82, 10];
console.log("Sorted array:", mergeSort(array));