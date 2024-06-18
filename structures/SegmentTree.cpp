#include "SegmentTree.h"


SegmentTreeNode::SegmentTreeNode(
    int _value,
    int _left_value,
    int _right_value,
    std::unique_ptr<SegmentTreeNode> _left,
    std::unique_ptr<SegmentTreeNode> _right
) {
    value = _value;
    left_range = _left_value;
    right_range = _right_value;
    left = std::move(_left);
    right = std::move(_right);
}


SegmentTreeNode::SegmentTreeNode(int _value, int _left_value, int _right_value) {
    SegmentTreeNode(_value, _left_value, _right_value, NULL, NULL);
}


SegmentTreeNode::SegmentTreeNode(int _value) {
    SegmentTreeNode(_value, _value, _value, NULL, NULL);
}


SumSegmentTree::SumSegmentTree(std::vector<int> values) {
    head = SumSegmentTree::makeNode(values);
}


std::unique_ptr<SegmentTreeNode> SumSegmentTree::makeNode(std::vector<int> values) {
    if (values.size() == 0) {
        return NULL;
    }

    if (values.size() == 1) {
        return std::make_unique<SegmentTreeNode>(values[0]);
    }

    int min = INT_MIN;
    int max = INT_MAX;
    int sum = 0;
    for (int value : values) {
        sum += value;
        min = std::min(min, value);
        max = std::max(max, value);
    }

    int middle = values.size() / 2;
    
    return std::make_unique<SegmentTreeNode>(
        sum, min, max,
        SumSegmentTree::makeNode({values.begin(), values.begin() + middle}),
        SumSegmentTree::makeNode({values.begin() + middle, values.end()})
    );
}


void SumSegmentTree::update(int old_value, int value) {
    head = SumSegmentTree::update_helper(std::move(head), old_value, value);
}

std::unique_ptr<SegmentTreeNode> SumSegmentTree::update_helper(
    std::unique_ptr<SegmentTreeNode> node, int old_value, int value
) {
    if (node->value == old_value) {
        node->value = value;
        return node;
    }

    if (value < node->value) {
        node->left = update_helper(std::move(node->left), old_value, value);
        return node;

    } else {
        node->right = update_helper(std::move(node->right), old_value, value);
        return node;
    }
}


/*
int SumSegmentTree::get_range_value(int left, int right) {
    
}
*/
