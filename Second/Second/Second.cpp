// Second.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class Actor
{
	Actor() : state_(nullptr)
	{
		// 대기 상태에서 시작
		changeState(new WaitState(this));
	}

	~Actor()
	{
		delete state_;
	}

	// 상태 업데이트
	void update(float time)
	{
		state_->update(time); // 현재 상태의 업데이트 실행
	}

	// 상태 변경
	void changeState(ActorState* state)
	{
		delete state_; // 오래된 상태 제거
		state_ = state; // 새로운 상태 설정
	}

	// .. 생략

private:
	ActorState* state_; // 현재 상태 클래스
};

// 상태 추상 인터페이스
class ActorState
{
public:
	virtual ~ActorState() {}
	// 업데이트
	virtual void update(float time) = 0;
};

// 대기상태
class WaitState : public ActorState
{
public:
	// 생성자
	WaitState(Actor* owner) : owner_(owner)
	{
		// 대기 상태의 초기화 처리
	}

	// 소멸자
	~WaitState()
	{
		// 대기 상태의 종료 처리
	}

	virtual void update(float time) override
	{
		// 대기 상태의 구현
		// 전투 중인지 확인
		/*
		if (owner_->isAttack())
		{
			// 공격 상태로 변경
			owner_->changeState(new AttackState(owner_));
		}
		*/
	}

private:
	Actor* owner_; // 상태의 소유자
};

int main()
{
    return 0;
}

