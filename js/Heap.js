const { measureAndPrintJob } = require('./Common');

function insertValue(heap, value, compare) {
    heap.push(value);

    let currentIndex = heap.length - 1;

    while (currentIndex > 0) {
        const currentValue = heap[currentIndex];
        const parentIndex = Math.floor((currentIndex - 1) / 2);
        const parentValue = heap[parentIndex];

        if (compare(parentValue, currentValue) > 0) {
            heap[currentIndex] = parentValue;
            heap[parentIndex] = currentValue;

            currentIndex = parentIndex;
        } else {
            break;
        }
    }
}

// =========================================

measureAndPrintJob('Min heap test', () => {
    const heap = [];
    const values = [3, 2, 10, 8, 6, 4];

    values.forEach(value => {
        insertValue(heap, value, (v1, v2) => v1 - v2);
    });

    console.log(heap);
});

measureAndPrintJob('Max heap test', () => {
    const heap = [];
    const values = [3, 2, 10, 8, 6, 4];

    values.forEach(value => {
        insertValue(heap, value, (v1, v2) => v2 - v1);
    });

    console.log(heap);
});
