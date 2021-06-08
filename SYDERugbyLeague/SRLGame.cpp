#include "SRLGame.h"

SRLGameManager::SRLGameManager()
{
	m_SecondsPassed = 0;
	m_MinutesPassed = 0;
}

SRLGameManager::~SRLGameManager()
{
}

void SRLGameManager::addPlay(string a_Play)
{
	string minutesStr = to_string(m_MinutesPassed);
	if (minutesStr.length() == 1)
	{
		minutesStr = "0" + minutesStr;
	}
	string secondsStr = to_string(m_SecondsPassed);
	if (secondsStr.length() == 1)
	{
		secondsStr = "0" + secondsStr;
	}
	m_PlayByPlay.push_back(minutesStr + ":" + secondsStr + " - "  + a_Play);
}

void SRLGameManager::addPlay(string a_Play, SRLPlayer player)
{
	string minutesStr = to_string(m_MinutesPassed);
	if (minutesStr.length() == 1)
	{
		minutesStr = "0" + minutesStr;
	}
	string secondsStr = to_string(m_SecondsPassed);
	if (secondsStr.length() == 1)
	{
		secondsStr = "0" + secondsStr;
	}
	m_PlayByPlay.push_back(minutesStr + ":" + secondsStr + " - " + player.getName() + " - " + a_Play);
}



void SRLGameManager::addStartTimePlay()
{
	addPlay("KICK OFF - " + m_HomeTeam.getName() + ": " + to_string(homeTeamScore) + " v " + m_AwayTeam.getName() + ": " + to_string(awayTeamScore));
}

void SRLGameManager::addFullTimePlay()
{
	addPlay("FULL TIME - " + m_HomeTeam.getName() + ": " + to_string(homeTeamScore) + " v " + m_AwayTeam.getName() + ": " + to_string(awayTeamScore));
}

void SRLGameManager::endStats()
{
	m_HomeTeam.saveTeam();
	m_AwayTeam.saveTeam();
}

void SRLGameManager::play()
{
	//DO WE DO AN INTERCHANGE
	if (m_SecondsPassed % 10 == 0 && m_MinutesPassed > 5)
	{
		int interchangeHomeTeam = (rand() % 50) + 1;
		int interchangeAwayTeam = (rand() % 50) + 1;

		if (interchangeHomeTeam > 40)
		{
			string swap = m_HomeTeam.Interchange();
			if (swap != "")
			{
				addPlay(swap);
			}
		}

		if (interchangeAwayTeam > 40)
		{
			string swap = m_AwayTeam.Interchange();
			if (swap != "")
			{
				addPlay(swap);
			}
		}
	}

	//CALLED EVERY SECOND
	m_SecondsPassed += 16;
	if (m_SecondsPassed >= 60)
	{
		m_SecondsPassed -= 60;
		m_MinutesPassed++;
		if (m_MinutesPassed >= 40 && halfTimeHasPassed == false)
		{
			halfTimeHasPassed = true;
			m_PlayByPlay.push_back("40:00 - HALF TIME - " + m_HomeTeam.getName() + ": " + to_string(homeTeamScore) + " v " + m_AwayTeam.getName() + ": " + to_string(awayTeamScore));
			m_BallPosition = 0;
			m_HomeTeamHasBall = false;
			m_Tackle = 0;
			return;
		}
	}
	SRLPlayer defender = m_AwayTeam.getRandomPlayer();
	SRLPlayer attacker = m_HomeTeam.getRandomPlayer();
	if (!m_HomeTeamHasBall)
	{
		defender = m_HomeTeam.getRandomPlayer();
		attacker = m_AwayTeam.getRandomPlayer();
	}

	//CHECK FOR ERRORS
	int atkError1 = (rand() % 100);
	int defError1 = (rand() % 100);
	if (atkError1 > attacker.getAttack())
	{
		//1 in 4 chance of error
		int atkError2 = (rand() % 4);
		if (atkError2 == 0)
		{
			addPlay("Knock On", attacker);
			changeOver(true);
			return;
		}
		//1 in 4 chance of error
		int atkError3 = (rand() % 4);
		if (atkError3 == 0)
		{
			addPlay("Over The Sideline", attacker);
			changeOver(false);
			return;
		}
		int atkError4 = (rand() % 4);
		if (atkError4 == 0)
		{
			addPlay("Forward Pass", attacker);
			changeOver(false);
			return;
		}
	}
	else if (defError1 > defender.getDefence())
	{
		//1 in 4 chance of error
		int defError2 = (rand() % 4);
		if (defError2 == 0)
		{
			addPlay("Ruck Infringement", defender);
			m_Tackle = 0;
			//changeOver(true);
		}
		//1 in 4 chance of error
		int defError3 = (rand() % 4);
		if (defError3 == 0)
		{
			addPlay("Penalty", defender);
			m_Tackle = 0;
			if (m_HomeTeamHasBall)
			{
				if (m_BallPosition < 30 && (homeTeamScore - awayTeamScore) > -3)
				{
					//1 in 4 chance of error
					int goal = (rand() % 4);
					if (goal != 0)
					{
						homeTeamScore += 2;
						addPlay("PENALTY GOAL - " + m_HomeTeam.getName() + ": " + to_string(homeTeamScore) + " v " + m_AwayTeam.getName() + ": " + to_string(awayTeamScore), attacker);
						m_BallPosition = 100;
					}
					else
					{
						addPlay("PENALTY GOAL MISSED", attacker);
						m_BallPosition = 50;
					}
					m_MinutesPassed++;
					if (!halfTimeHasPassed && m_MinutesPassed >= 40)
					{
						m_MinutesPassed = 40;
						m_SecondsPassed = 0;
					}
				}
				else if (m_BallPosition < 30)
				{
					m_BallPosition = 10;
				}
				else
				{
					m_BallPosition -= 30;
				}
			}
			else
			{
				if (m_BallPosition > 70 && (awayTeamScore - homeTeamScore) > -3)
				{
					//1 in 4 chance of error
					int goal = (rand() % 4);
					if (goal != 0)
					{
						awayTeamScore += 2;
						addPlay("PENALTY GOAL - " + m_HomeTeam.getName() + ": " + to_string(homeTeamScore) + " v " + m_AwayTeam.getName() + ": " + to_string(awayTeamScore), attacker);
						m_BallPosition = 0;
					}
					else
					{
						addPlay("PENALTY GOAL MISSED", attacker);
						m_BallPosition = 50;
					}
					m_MinutesPassed++;
					if (!halfTimeHasPassed && m_MinutesPassed >= 40)
					{
						m_MinutesPassed = 40;
						m_SecondsPassed = 0;
					}
				}
				else if (m_BallPosition > 70)
				{
					m_BallPosition = 90;
				}
				else
				{
					m_BallPosition += 30;
				}
			}
			return;
		}
	}

	//MOVEMENT
	if (m_HomeTeamHasBall)
	{
		if (attacker.getAttack() > defender.getDefence())
		{
			m_BallPosition -= ((rand() % (attacker.getAttack() - defender.getDefence())) + ((attacker.getSpeed() / 20) + 1)) / 2;
		}
		else
		{
			m_BallPosition -= (((attacker.getSpeed() / 20) + 1)) / 2;
		}
	}
	else
	{
		if (attacker.getAttack() > defender.getDefence())
		{
			m_BallPosition += ((rand() % (attacker.getAttack() - defender.getDefence())) + ((attacker.getSpeed() / 20) + 1)) / 2;
		}
		else
		{
			m_BallPosition += (((attacker.getSpeed() / 20) + 1)) / 2;
		}
	}
	m_Tackle++;

	//CHANCE FOR STRIP
	if (defender.getSpeed() > attacker.getSpeed())
	{
		if (defender.getDefence() > attacker.getAttack())
		{
			int chance1 = defender.getDefence() - attacker.getAttack();
			int chance2 = rand() % 100;
			if (chance1 > chance2)
			{
				addPlay("Stripped Ball Off " + attacker.getName(), defender);
				changeOver(false);
			}
		}
	}
	if (m_MinutesPassed > 50)
	{
		if ((m_Tackle == 5 && ((homeTeamScore - awayTeamScore >= 0 && (homeTeamScore - awayTeamScore) % 6 == 0) || homeTeamScore - awayTeamScore == -1)) || homeTeamScore == awayTeamScore)
		{
			if (m_BallPosition < 30 && m_BallPosition > 0 && m_HomeTeamHasBall)
			{
				int chance1 = attacker.getAttack();
				int chance2 = rand() % 100;
				if (chance1 > chance2)
				{
					homeTeamScore += 1;
					addPlay("FIELD GOAL - " + m_HomeTeam.getName() + ": " + to_string(homeTeamScore) + " v " + m_AwayTeam.getName() + ": " + to_string(awayTeamScore), attacker);
					m_BallPosition = 100;
				}
				else
				{
					addPlay("FIELD GOAL MISSED", attacker);
					m_BallPosition = 20;
					changeOver(true);
				}
				m_Tackle = 0;
				return;
			}
		}
		else if ((m_Tackle == 5 && ((awayTeamScore - homeTeamScore >= 0 && (awayTeamScore - homeTeamScore) % 6 == 0) || awayTeamScore - homeTeamScore == -1)) || homeTeamScore == awayTeamScore)
		{
			if (m_BallPosition > 70 && m_BallPosition < 100 && !m_HomeTeamHasBall)
			{
				int chance1 = attacker.getAttack();
				int chance2 = rand() % 100;
				if (chance1 > chance2)
				{
					awayTeamScore += 1;
					addPlay("FIELD GOAL - " + m_HomeTeam.getName() + ": " + to_string(homeTeamScore) + " v " + m_AwayTeam.getName() + ": " + to_string(awayTeamScore), attacker);
					m_BallPosition = 0;
				}
				else
				{
					addPlay("FIELD GOAL MISSED", attacker);
					m_BallPosition = 80;
					changeOver(true);
				}
				m_Tackle = 0;
				return;
			}
		}
	}
	//END OF SET, CHANGEOVER
	if (m_Tackle == 6)
	{
		addPlay("6th Tackle Changeover", attacker);
		changeOver(false);
		return;
	}

	//CHECK FOR POINTS
	else if (m_BallPosition < 0 && m_HomeTeamHasBall)
	{
		homeTeamScore += 4;
		addPlay("TRY - " + m_HomeTeam.getName() + ": " + to_string(homeTeamScore) + " v " + m_AwayTeam.getName() + ": " + to_string(awayTeamScore), attacker);
		m_MinutesPassed++;
		if (!halfTimeHasPassed && m_MinutesPassed >= 40)
		{
			m_MinutesPassed = 40;
			m_SecondsPassed = 0;
		}
		int goal1 = (rand() % 100);
		if (goal1 < attacker.getAttack())
		{
			//1 in 4 chance of error
			int goal2 = (rand() % 4);
			if (goal2 != 0)
			{
				homeTeamScore += 2;
				addPlay("GOAL - " + m_HomeTeam.getName() + ": " + to_string(homeTeamScore) + " v " + m_AwayTeam.getName() + ": " + to_string(awayTeamScore), attacker);
			}
			else
			{
				addPlay("CONVERSION MISSED", attacker);
			}
		}
		else
		{
			addPlay("CONVERSION MISSED", attacker);
		}
		m_MinutesPassed++;
		if (m_MinutesPassed >= 40 && halfTimeHasPassed == false)
		{
			halfTimeHasPassed = true;
			m_PlayByPlay.push_back("40:00 - HALF TIME - " + m_HomeTeam.getName() + ": " + to_string(homeTeamScore) + " v " + m_AwayTeam.getName() + ": " + to_string(awayTeamScore));
			m_BallPosition = 0;
			m_HomeTeamHasBall = false;
			m_Tackle = 0;
			return;
		}
		m_BallPosition = 100;
		m_Tackle = 0;
	}
	//CHECK FOR POINTS
	else if (m_BallPosition > 100 && !m_HomeTeamHasBall)
	{
		awayTeamScore += 4;
		addPlay("TRY - " + m_HomeTeam.getName() + ": " + to_string(homeTeamScore) + " v " + m_AwayTeam.getName() + ": " + to_string(awayTeamScore), attacker);
		m_MinutesPassed++;
		if (!halfTimeHasPassed && m_MinutesPassed >= 40)
		{
			m_MinutesPassed = 40;
			m_SecondsPassed = 0;
		}
		int goal1 = (rand() % 100);
		if (goal1 < attacker.getAttack())
		{
			//1 in 4 chance of error
			int goal2 = (rand() % 4);
			if (goal2 != 0)
			{
				awayTeamScore += 2;
				addPlay("GOAL - " + m_HomeTeam.getName() + ": " + to_string(homeTeamScore) + " v " + m_AwayTeam.getName() + ": " + to_string(awayTeamScore), attacker);
			}
			else
			{
				addPlay("CONVERSION MISSED", attacker);
			}
		}
		else
		{
			addPlay("CONVERSION MISSED", attacker);
		}
		m_MinutesPassed++;
		if (m_MinutesPassed >= 40 && halfTimeHasPassed == false)
		{
			halfTimeHasPassed = true;
			m_PlayByPlay.push_back("40:00 - HALF TIME - " + m_HomeTeam.getName() + ": " + to_string(homeTeamScore) + " v " + m_AwayTeam.getName() + ": " + to_string(awayTeamScore));
			m_BallPosition = 0;
			m_HomeTeamHasBall = false;
			m_Tackle = 0;
			return;
		}
		m_BallPosition = 0;
		m_Tackle = 0;
	}
	
}

void SRLGameManager::changeOver(bool error)
{
	if (error)
	{
		m_Tackle = -1;
	}
	else
	{
		m_Tackle = 0;
	}
	m_HomeTeamHasBall = !m_HomeTeamHasBall;
}