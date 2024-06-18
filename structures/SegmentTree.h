#include <memory>
#include <vector>


class SegmentTreeNode {
    public:
        SegmentTreeNode(
            int value,
            int left_range,
            int right_range,
            std::unique_ptr<SegmentTreeNode> left,
            std::unique_ptr<SegmentTreeNode> right
        );

        SegmentTreeNode(int value, int left_range, int right_range);
        SegmentTreeNode(int value);

        int value;
        int left_range;
        int right_range;
        std::unique_ptr<SegmentTreeNode> left;
        std::unique_ptr<SegmentTreeNode> right;
};


class SumSegmentTree {
    public:
        SumSegmentTree(std::vector<int> values);

        void update(int old_value, int value);
        //int get_range_value(int left, int right);

    private:
        std::unique_ptr<SegmentTreeNode> makeNode(std::vector<int> values);
        std::unique_ptr<SegmentTreeNode> update_helper(std::unique_ptr<SegmentTreeNode> node, int old_value, int value);
        //int get_range_value_helper(int left, int right);

        std::unique_ptr<SegmentTreeNode> head;
};
