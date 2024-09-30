#include "Framework.h"

Camera::Camera()
{
	SetType(ComponentType::Camera);
	_distance = { 0,0 };
	_resolution = { MAX_WIDTH, MAX_HEIGHT };
	_lookposition = { 0, 0 };
	_target = nullptr;
	_isActive = true;
	offset = { 0,0 };
}

Camera::~Camera()
{
}

void Camera::SetZoom(float factor)
{
    _zoomLevel = factor;
    UpdateResolution();
}

void Camera::ZoomIn(float factor)
{
    _zoomLevel *= factor;
    UpdateResolution();
}

void Camera::ZoomOut(float factor)
{
    _zoomLevel /= factor;
    UpdateResolution();
}

void Camera::UpdateResolution()
{
    Vector2 oldResolution = _resolution;
    _resolution.x = MAX_WIDTH / _zoomLevel;
    _resolution.y = MAX_HEIGHT / _zoomLevel;

    // 줌 변경 후 중심 유지
    Vector2 centerOffset = (oldResolution - _resolution);
    centerOffset /= 2;
    _distance += centerOffset;

    UpdateLookPosition();
}

void Camera::UpdateLookPosition()
{
    if (_target)
    {
        Transform* tr = _target->GetComponent<Transform>();
        _lookposition = tr->worldPosition + (tr->scale / 2);
    }
    else
    {
        Transform* cameraTr = GetOwner()->GetComponent<Transform>();
        _lookposition = cameraTr->worldPosition + (cameraTr->scale / 2);
    }

    _lookposition.x = std::ceil(max(_resolution.x / 2, min(_lookposition.x, _mapSize.x - _resolution.x / 2)));
    _lookposition.y = std::ceil(max(_resolution.y / 2, min(_lookposition.y, _mapSize.y - _resolution.y / 2)));
}

void Camera::Update()
{
    if (_isActive)
    {
        if (SceneManager::Get()->GetActiveScene() != nullptr)
        {
            _mapSize = SceneManager::Get()->GetActiveScene()->MapSize + offset;
        }

        UpdateLookPosition();

        const float lerpSpeed = 5.0f; // 이동 속도를 조절할 수 있는 값
        _distance = _distance.Lerp(_distance, _lookposition - (_resolution / 2.0f), lerpSpeed * DELTA);
        _distance.x = std::ceil(_distance.x);
        _distance.y = std::ceil(_distance.y);
    }
}



void Camera::SetMainCamera()
{
	RenderManager::Get()->SetCamera(this);
}
