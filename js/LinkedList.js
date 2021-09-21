const { measureAndPrintJob } = require('./Common');

function createNode(value, nextNode = null, previousNode = null) {
    return { value, nextNode, previousNode };
}

function linkNodes(node1, node2) {
    node1.nextNode = node2;
    node2.previousNode = node1;
}

function insertAfter(currentNode, newNode) {
    const nextNode = currentNode.nextNode;

    linkNodes(currentNode, newNode);

    if (nextNode !== null) {
        linkNodes(newNode, nextNode)
    }
}

function insertBefore(currentNode, newNode) {
    const previousNode = currentNode.previousNode;

    linkNodes(newNode, currentNode);

    if (previousNode !== null) {
        linkNodes(previousNode, newNode);
    }
}

function removeAt(node) {
    if (node.previousNode !== null) {
        if (node.nextNode !== null) {
            linkNodes(node.previousNode, node.nextNode);
        } else {
            node.previousNode.nextNode = null;
        }
    } else {
        if (node.nextNode !== null) {
            node.nextNode.previousNode = null;
        }
    }
}

function mapFrom(node, job) {
    const result = [];
    let currentNode = node;

    while (currentNode !== null) {
        result.push(job(currentNode));
        currentNode = currentNode.nextNode;
    }

    return result;
}

function nodeToString(node) {
    return `${node.previousNode ? node.previousNode.value : 'X'} -> <${node.value}> -> ${node.nextNode ? node.nextNode.value : 'X'}`
}

// =========================================

measureAndPrintJob('Insertion test 1', () => {
    const node1 = createNode(1);
    const node2 = createNode(2);
    const node3 = createNode(3);

    insertAfter(node1, node2);
    insertAfter(node1, node3);

    console.log(mapFrom(node1, node => nodeToString(node)));
});

measureAndPrintJob('Insertion test 2', () => {
    const node1 = createNode(1);
    const node2 = createNode(2);
    const node3 = createNode(3);

    insertAfter(node1, node2);
    insertBefore(node1, node3);

    console.log(mapFrom(node3, node => nodeToString(node)));
});

measureAndPrintJob('Removal test', () => {
    const node1 = createNode(1);
    const node2 = createNode(2);
    const node3 = createNode(3);
    const node4 = createNode(4);
    const node5 = createNode(5);

    insertAfter(node1, node2);
    insertAfter(node2, node3);
    insertAfter(node3, node4);
    insertAfter(node4, node5);

    removeAt(node2);
    removeAt(node1);
    removeAt(node4);

    console.log(mapFrom(node3, node => nodeToString(node)));
});

(() => {
    let currentNode = null;
    const count = 100000;

    measureAndPrintJob('Front insertion performance (Linked list)', () => {
        for (let i = 0; i < count; i++) {
            const newNode = createNode(i);

            if (currentNode !== null) {
                insertBefore(currentNode, newNode);
            }

            currentNode = newNode;
        }
    });

    measureAndPrintJob('Front insertion performance (Array)', () => {
        const nodes = [];

        for (let i = 0; i < count; i++) {
            nodes.unshift(i);
        }
    });

    measureAndPrintJob('Back insertion performance (Linked list)', () => {
        for (let i = 0; i < count; i++) {
            const newNode = createNode(i);

            if (currentNode !== null) {
                insertAfter(currentNode, newNode);
            }

            currentNode = newNode;
        }
    });

    measureAndPrintJob('Back insertion performance (Array)', () => {
        const nodes = [];

        for (let i = 0; i < count; i++) {
            nodes.push(i);
        }
    });
})();
