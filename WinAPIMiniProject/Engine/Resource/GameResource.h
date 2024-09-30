#pragma once

// 추상 클래스로 선언 (abstract)
// : 자식만 사용한다는 뜻이라네요? 어쨋든 이 클래스는 상속을 위해 기본적으로 만들었습니다.
// 결론은 자식클래스만 사용한다는 뜻입니당
class GameResource abstract
{
public:

	GameResource(ResourceType _type);
	virtual ~GameResource();

	const std::wstring GetPath() { return m_path; }
	const ResourceType GetType() { return m_type; }
	const ExtType GetExt() { return m_ext; }

	void SetPath(const std::wstring& _path) { m_path = _path; }
	void SetExt(ExtType _type) { m_ext = _type; }

private:

	std::wstring m_path; // 경로
	ResourceType m_type; // 리소스 타입
	ExtType m_ext; // 리소스 확장자

};