#pragma once

class Timer {
public:
	explicit Timer(float duration = 0.0f) : m_Duration(duration) {}

	void Update(float deltaTime) {
		if (IsFinished()) return;

		m_Elapsed += deltaTime;

		if (m_Elapsed > m_Duration) {
			m_Elapsed = m_Duration;
		}
	}

	bool IsFinished() const {
		return m_Elapsed >= m_Duration;
	}

	void Reset() {
		m_Elapsed = 0.0f;
	}

	void SetDuration(float duration) {
		m_Duration = duration;
		Reset();
	}

	float GetDuration() const { return m_Duration; }

	float GetRemaining() const {
		return m_Duration - m_Elapsed;
	}
private:
	float m_Duration = 0.0f;
	float m_Elapsed = 0.0f;
};