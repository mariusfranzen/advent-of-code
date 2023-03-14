#!/usr/bin/env node
import fs = require('fs');

const text: string = fs.readFileSync('./input.txt').toString();
const lines: string[] = text.split('\n');

// Generate trees[][] that stores all trees and their heights
// Generate visibleTrees[][] that stores 1 if the tree is visible and 0 if it's invisible

const trees: number[][] = [];
const visibleTrees: number[][] = [];

for (let row = 0; row < lines.length; row++) {
    const newRow: number[] = [];
    const newVisibleRow: number[] = [];

    for (let col = 0; col < lines[row].length; col++) {
        if (!Number.isNaN(Number.parseInt(lines[row][col]))) {
            newRow.push(Number.parseInt(lines[row][col]));
            newVisibleRow.push(1);
        }
    }
    trees.push(newRow);
    visibleTrees.push(newVisibleRow);
}

for (let row = 1; row < visibleTrees.length - 1; row++) {
    for (let col = 1; col < visibleTrees[row].length - 1; col++) {
        if (!Number.isNaN(Number.parseInt(lines[row][col]))) {
            visibleTrees[row][col] = 0;
        }
    }
}

const totalRows = trees.length;
const totalCols = trees[0].length;

// Iterate left -> right

for (let row = 0; row < totalRows; row++) {
    let maxHeight = trees[row][0];

    for (let col = 0; col < totalCols; col++) {
        if (trees[row][col] > maxHeight) {
            maxHeight = trees[row][col];
            visibleTrees[row][col] = 1;
        }
    }
}

// Iterate right -> left

for (let row = 0; row < totalRows; row++) {
    let maxHeight = trees[row][trees[row].length - 1];

    for (let col = totalCols - 1; col > 0; col--) {
        if (trees[row][col] > maxHeight) {
            maxHeight = trees[row][col];
            visibleTrees[row][col] = 1;
        }
    }
}

// Iterate top -> bottom

for (let col = 0; col < totalCols; col++) {
    let maxHeight = trees[0][col];

    for (let row = 0; row < totalRows; row++) {
        if (trees[row][col] > maxHeight) {
            maxHeight = trees[row][col];
            visibleTrees[row][col] = 1;
        }
    }
}

// Iterate bottom -> top

for (let col = 0; col < totalCols; col++) {
    let maxHeight = trees[totalRows - 1][col];

    for (let row = totalRows - 1; row > 0; row--) {
        if (trees[row][col] > maxHeight) {
            maxHeight = trees[row][col];
            visibleTrees[row][col] = 1;
        }
    }
}

// Visualize

let totalVisibleTrees = 0;

for (let row = 0; row < totalRows; row++) {
    console.log(visibleTrees[row].join(''));
    for (let col = 0; col < totalCols; col++) {
        if (visibleTrees[row][col] > 0) {
            totalVisibleTrees++;
        }
    }
}

console.log(`Total visible trees: ${totalVisibleTrees}`);
