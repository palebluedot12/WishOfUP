#pragma once

// �߻� Ŭ������ ���� (abstract)
// : �ڽĸ� ����Ѵٴ� ���̶�׿�? ��¶�� �� Ŭ������ ����� ���� �⺻������ ��������ϴ�.
// ����� �ڽ�Ŭ������ ����Ѵٴ� ���Դϴ�
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

	std::wstring m_path; // ���
	ResourceType m_type; // ���ҽ� Ÿ��
	ExtType m_ext; // ���ҽ� Ȯ����

};