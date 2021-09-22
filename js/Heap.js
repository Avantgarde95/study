const { measureAndPrintJob } = require('./Common');

function insertValue(heap, value, compare) {
    heap.push(value);

    const heapSize = heap.length;
    let currentIndex = heapSize - 1;

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

function removeRoot(heap, compare) {
    const heapSize = heap.length;

    if (heapSize <= 0) {
        return;
    } else if (heapSize === 1) {
        heap.pop();
        return;
    }

    heap[0] = heap.pop();

    let currentIndex = 0;

    while (true) {
        const child1Index = currentIndex * 2 + 1;

        if (child1Index >= heapSize) {
            break;
        }

        const currentValue = heap[currentIndex];
        const child1Value = heap[child1Index];

        let child2Index = currentIndex * 2 + 2;

        if (child2Index >= heapSize) {
            child2Index = child1Index;
        }

        const child2Value = heap[child2Index];
        let minChildIndex;
        let minChildValue;

        if (compare(child1Value, child2Value) <= 0) {
            minChildIndex = child1Index;
            minChildValue = child1Value;
        } else {
            minChildIndex = child2Index;
            minChildValue = child2Value;
        }

        if (compare(currentValue, minChildValue) > 0) {
            heap[currentIndex] = minChildValue;
            heap[minChildIndex] = currentValue;
            currentIndex = minChildIndex;
        } else {
            break;
        }
    }
}

// =========================================

measureAndPrintJob('Min heap test', () => {
    const heap = [];
    const values = [3, 2, 3, 8, 6, 4];
    const compare = (v1, v2) => v1 - v2;

    values.forEach(value => {
        insertValue(heap, value, compare);
        console.log(`Insert ${value} -> [${heap.join(', ')}]`);
    });

    for (let i = 0; i < 5; i++) {
        removeRoot(heap, compare);
        console.log(`Delete root -> [${heap.join(', ')}]`);
    }
});

measureAndPrintJob('Max heap test', () => {
    const heap = [];
    const values = [3, 2, 3, 8, 6, 4];

    const compare = (v1, v2) => v2 - v1;

    values.forEach(value => {
        insertValue(heap, value, compare);
        console.log(`Insert ${value} -> [${heap.join(', ')}]`);
    });

    for (let i = 0; i < 5; i++) {
        removeRoot(heap, compare);
        console.log(`Delete root -> [${heap.join(', ')}]`);
    }
});
