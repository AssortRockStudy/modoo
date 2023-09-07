#include "pch.h"
#include "CLevelMgr.h"


#include "CEngine.h"
#include "CLevel.h"


// 임시
#include "CPlayer.h"
#include "CMonster.h"

CLevelMgr::CLevelMgr()
	: m_pCurLevel(nullptr)
{}


CLevelMgr::~CLevelMgr()
{
	delete m_pCurLevel;
}

void CLevelMgr::init()
{
	// Level 생성
	m_pCurLevel = new CLevel;

	// Plyaer 생성
	CPlayer* pPlayer = new CPlayer;
	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));
	m_pCurLevel->AddObject(pPlayer);

	CMonster* pMonster = new CMonster;
	pMonster->SetPos(Vec2(500.f, 600.f));
	pMonster->SetScale(Vec2(50.f, 50.f));
	m_pCurLevel->AddObject(pMonster);

}

void CLevelMgr::tick()
{
	m_pCurLevel->tick();
}

void CLevelMgr::render(HDC _dc)
{
	POINT ptResolution = CEngine::GetInst()->GetResolution();


	// 화면 clear
	Rectangle(_dc, -1, -1, ptResolution.x + 1, ptResolution.y);



	// Level render
	m_pCurLevel->render(_dc);


}
