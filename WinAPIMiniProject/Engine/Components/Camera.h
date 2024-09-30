#pragma once

class Camera : public Component
{
public:

    Vector2 CalculatePosition(Vector2 pos) {
        float newX = std::ceil((pos.x - _distance.x) * _zoomLevel);
        float newY = std::ceil((pos.y - _distance.y) * _zoomLevel); // pos.y ���� ����� ���
        return { newX, newY };
    };
    Vector2 CalculateSize(const Vector2& size) const {
        float newX = std::ceil(size.x * _zoomLevel);
        float newY = std::ceil(size.y * _zoomLevel);
        return { newX, newY };
    }

    Camera();
    ~Camera();

    void Update()override;

    void SetTarget(GameObject* target) { _target = target; }
    void SetMainCamera();
    void SetMapSize(Vector2 mapSize) { _mapSize = mapSize; } // �� ũ�� ����
    void SetActive(bool _val) { _isActive = _val; }

    Vector2 GetViewportMin() const { return _distance; }
    Vector2 GetViewportMax() const { return _distance + _resolution; }
    bool GetActive() { return _isActive; }

    void SetZoom(float factor);
    void ZoomIn(float factor);
    void ZoomOut(float factor);
    float GetZoom() { return _zoomLevel; }
    void UpdateResolution();
    float GetZoomLevel() { return _zoomLevel; };

    void UpdateLookPosition();

    Vector2 offset;

private:

    GameObject* _target;

    Vector2 _distance; // ī�޶� �̵� �Ÿ�
    Vector2 _resolution;
    Vector2 _lookposition;
    Vector2 _mapSize; // �� ũ��

    float _zoomLevel = 1.0f;
    bool _isActive;

};