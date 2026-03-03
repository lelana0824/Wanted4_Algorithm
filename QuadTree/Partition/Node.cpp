#include "Node.h"

Node::Node(const Bounds& bounds, int depth)
    : bounds(bounds), depth(depth)
{

}
bool Node::Subdivide()
{
    // 최대 깊이 (임시값 사용) 도달했는지 확인
    if (depth == 5)
    {
        return false;
    }

    // 분할 여부 파악
    // 분할 전이면 영역 나누기.
    if (!IsDivided())
    {
        int x = bounds.X();
        int y = bounds.Y();
        int halfWidth = bounds.Width() / 2;
        int halfHeight = bounds.Height() / 2;

        // 각 4분면의 자식 객체 생성
        topLeft = new Node(
            Bounds(x, y, halfWidth, halfHeight),
            depth + 1
        );

        topRight = new Node(
            Bounds(x + halfWidth, y, halfWidth, halfHeight),
            depth + 1
        );

        bottomLeft = new Node(
            Bounds(x, y + halfHeight, halfWidth, halfHeight),
            depth + 1
        );

        bottomRight = new Node(
            Bounds(x + halfWidth, y + halfHeight, halfWidth, halfHeight),
            depth + 1
        );
    }
    return true;
}

bool Node::IsDivided()
{
    // 분할할때는 모든 자식노드가 null이 아니기 때문에 
    // 하나의 자식만 파악해도 됨.
    return topLeft != nullptr;
}

NodeIndex Node::TestRegion(const Bounds& bounds)
{
    return NodeIndex();
}

std::vector<NodeIndex> Node::GetQuads(const Bounds& bounds)
{
    // 겹치는 영역 반환을 위한 변수
    std::vector<NodeIndex> quads;

    // 영역 계산에 필요한 변수.
    int x = this->bounds.X();
    int y = this->bounds.Y();
    int halfWidth = this->bounds.Width() / 2;
    int halfHeight = this->bounds.Height() / 2;
    int centerX = x + halfWidth;
    int centerY = y + halfHeight;

    // 왼쪽 영역이랑 겹치는지 확인.
    bool left
        = bounds.X() < centerX && bounds.MaxX() >= x;

    // 오른쪽 영역이랑 겹치는지 확인.
    bool right
        = bounds.MaxX() >= centerX && bounds.X() < this->bounds.MaxX();

    // 위쪽 영역이랑 겹치는지 확인.
    bool top = bounds.Y() < centerY && bounds.MaxY() >= y;

    // 아래쪽 영역이랑 겹치는지 확인.
    bool bottom
        = bounds.MaxY() >= centerY && bounds.Y() < this->bounds.MaxY();

    // 영역 판정.
    if (top && left)
    {
        quads.emplace_back(NodeIndex::TopLeft);
    }
    if (top && right)
    {
        quads.emplace_back(NodeIndex::TopRight);
    }
    if (bottom && left)
    {
        quads.emplace_back(NodeIndex::BottomLeft);
    }
    if (bottom && right)
    {
        quads.emplace_back(NodeIndex::BottomRight);
    }

    return quads;
}

void Node::ClearChildren()
{
    if (IsDivided())
    {
        SafeDelete(topLeft);
        SafeDelete(topRight);
        SafeDelete(bottomLeft);
        SafeDelete(bottomRight);
    }
}
