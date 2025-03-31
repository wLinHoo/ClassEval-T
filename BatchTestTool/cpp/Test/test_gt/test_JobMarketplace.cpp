#include <gtest/gtest.h>
#include "pch.h"

class JobMarketplaceTestPostJob : public ::testing::Test {
protected:
    JobMarketplace jobMarketplace;
};

TEST_F(JobMarketplaceTestPostJob, test_post_job) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "requirement1", "requirement2" });
    std::vector<Job> expected = { {"Software Engineer", "ABC Company", {"requirement1", "requirement2"}} };
    EXPECT_EQ(jobMarketplace.job_listings, expected);
}

TEST_F(JobMarketplaceTestPostJob, test_post_job_2) {
    jobMarketplace.post_job("Mechanical Engineer", "XYZ Company", { "requirement3", "requirement4" });
    std::vector<Job> expected = { {"Mechanical Engineer", "XYZ Company", {"requirement3", "requirement4"}} };
    EXPECT_EQ(jobMarketplace.job_listings, expected);
}

TEST_F(JobMarketplaceTestPostJob, test_post_job_3) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "requirement1", "requirement2" });
    jobMarketplace.post_job("Mechanical Engineer", "XYZ Company", { "requirement3", "requirement4" });
    std::vector<Job> expected = {
        {"Software Engineer", "ABC Company", {"requirement1", "requirement2"}},
        {"Mechanical Engineer", "XYZ Company", {"requirement3", "requirement4"}}
    };
    EXPECT_EQ(jobMarketplace.job_listings, expected);
}

TEST_F(JobMarketplaceTestPostJob, test_post_job_4) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "requirement1", "requirement2" });
    jobMarketplace.post_job("Mechanical Engineer", "XYZ Company", { "requirement3", "requirement4" });
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "requirement1", "requirement2" });
    std::vector<Job> expected = {
        {"Software Engineer", "ABC Company", {"requirement1", "requirement2"}},
        {"Mechanical Engineer", "XYZ Company", {"requirement3", "requirement4"}},
        {"Software Engineer", "ABC Company", {"requirement1", "requirement2"}}
    };
    EXPECT_EQ(jobMarketplace.job_listings, expected);
}

TEST_F(JobMarketplaceTestPostJob, test_post_job_5) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "requirement1", "requirement2" });
    jobMarketplace.post_job("Mechanical Engineer", "XYZ Company", { "requirement3", "requirement4" });
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "requirement1", "requirement2" });
    jobMarketplace.post_job("Mechanical Engineer", "XYZ Company", { "requirement3", "requirement4" });
    std::vector<Job> expected = {
        {"Software Engineer", "ABC Company", {"requirement1", "requirement2"}},
        {"Mechanical Engineer", "XYZ Company", {"requirement3", "requirement4"}},
        {"Software Engineer", "ABC Company", {"requirement1", "requirement2"}},
        {"Mechanical Engineer", "XYZ Company", {"requirement3", "requirement4"}}
    };
    EXPECT_EQ(jobMarketplace.job_listings, expected);
}

class JobMarketplaceTestRemoveJob : public ::testing::Test {
protected:
    JobMarketplace jobMarketplace;
};

TEST_F(JobMarketplaceTestRemoveJob, test_remove_job) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "requirement1", "requirement2" });
    jobMarketplace.remove_job(jobMarketplace.job_listings[0]);
    std::vector<Job> expected = {};
    EXPECT_EQ(jobMarketplace.job_listings, expected);
}

TEST_F(JobMarketplaceTestRemoveJob, test_remove_job_2) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "requirement1", "requirement2" });
    jobMarketplace.post_job("Mechanical Engineer", "XYZ Company", { "requirement3", "requirement4" });
    jobMarketplace.remove_job(jobMarketplace.job_listings[0]);
    std::vector<Job> expected = { {"Mechanical Engineer", "XYZ Company", {"requirement3", "requirement4"}} };
    EXPECT_EQ(jobMarketplace.job_listings, expected);
}

TEST_F(JobMarketplaceTestRemoveJob, test_remove_job_3) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "requirement1", "requirement2" });
    jobMarketplace.post_job("Mechanical Engineer", "XYZ Company", { "requirement3", "requirement4" });
    jobMarketplace.remove_job(jobMarketplace.job_listings[0]);
    jobMarketplace.remove_job(jobMarketplace.job_listings[0]);
    std::vector<Job> expected = {};
    EXPECT_EQ(jobMarketplace.job_listings, expected);
}

TEST_F(JobMarketplaceTestRemoveJob, test_remove_job_4) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "requirement1", "requirement2" });
    jobMarketplace.post_job("Mechanical Engineer", "XYZ Company", { "requirement3", "requirement4" });
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "requirement1", "requirement2" });
    jobMarketplace.remove_job(jobMarketplace.job_listings[0]);
    jobMarketplace.remove_job(jobMarketplace.job_listings[0]);
    std::vector<Job> expected = { {"Software Engineer", "ABC Company", {"requirement1", "requirement2"}} };
    EXPECT_EQ(jobMarketplace.job_listings, expected);
}

TEST_F(JobMarketplaceTestRemoveJob, test_remove_job_5) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "requirement1", "requirement2" });
    jobMarketplace.post_job("Mechanical Engineer", "XYZ Company", { "requirement3", "requirement4" });
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "requirement1", "requirement2" });
    jobMarketplace.remove_job(jobMarketplace.job_listings[0]);
    std::vector<Job> expected = { {"Mechanical Engineer", "XYZ Company", {"requirement3", "requirement4"}}, {"Software Engineer", "ABC Company", {"requirement1", "requirement2"}} };
    EXPECT_EQ(jobMarketplace.job_listings, expected);
}

class JobMarketplaceTestSubmitResume : public ::testing::Test {
protected:
    JobMarketplace jobMarketplace;
};

TEST_F(JobMarketplaceTestSubmitResume, test_submit_resume) {
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    std::vector<Resume> expected = { {"Tom", {"skill1", "skill2"}, "experience"} };
    EXPECT_EQ(jobMarketplace.resumes, expected);
}

TEST_F(JobMarketplaceTestSubmitResume, test_submit_resume_2) {
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    std::vector<Resume> expected = {
        {"Tom", {"skill1", "skill2"}, "experience"},
        {"John", {"skill3", "skill4"}, "experience"}
    };
    EXPECT_EQ(jobMarketplace.resumes, expected);
}

TEST_F(JobMarketplaceTestSubmitResume, test_submit_resume_3) {
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    std::vector<Resume> expected = {
        {"Tom", {"skill1", "skill2"}, "experience"},
        {"John", {"skill3", "skill4"}, "experience"},
        {"Tom", {"skill1", "skill2"}, "experience"}
    };
    EXPECT_EQ(jobMarketplace.resumes, expected);
}

TEST_F(JobMarketplaceTestSubmitResume, test_submit_resume_4) {
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    std::vector<Resume> expected = {
        {"Tom", {"skill1", "skill2"}, "experience"},
        {"John", {"skill3", "skill4"}, "experience"},
        {"Tom", {"skill1", "skill2"}, "experience"},
        {"John", {"skill3", "skill4"}, "experience"}
    };
    EXPECT_EQ(jobMarketplace.resumes, expected);
}

TEST_F(JobMarketplaceTestSubmitResume, test_submit_resume_5) {
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    std::vector<Resume> expected = {
        {"Tom", {"skill1", "skill2"}, "experience"},
        {"John", {"skill3", "skill4"}, "experience"},
        {"Tom", {"skill1", "skill2"}, "experience"},
        {"John", {"skill3", "skill4"}, "experience"},
        {"Tom", {"skill1", "skill2"}, "experience"}
    };
    EXPECT_EQ(jobMarketplace.resumes, expected);
}

class JobMarketplaceTestWithdrawResume : public ::testing::Test {
protected:
    JobMarketplace jobMarketplace;
};

TEST_F(JobMarketplaceTestWithdrawResume, test_withdraw_resume) {
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.withdraw_resume(jobMarketplace.resumes[0]);
    std::vector<Resume> expected = {};
    EXPECT_EQ(jobMarketplace.resumes, expected);
}

TEST_F(JobMarketplaceTestWithdrawResume, test_withdraw_resume_2) {
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    jobMarketplace.withdraw_resume(jobMarketplace.resumes[0]);
    std::vector<Resume> expected = { {"John", {"skill3", "skill4"}, "experience"} };
    EXPECT_EQ(jobMarketplace.resumes, expected);
}

TEST_F(JobMarketplaceTestWithdrawResume, test_withdraw_resume_3) {
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    jobMarketplace.withdraw_resume(jobMarketplace.resumes[0]);
    jobMarketplace.withdraw_resume(jobMarketplace.resumes[0]);
    std::vector<Resume> expected = {};
    EXPECT_EQ(jobMarketplace.resumes, expected);
}

TEST_F(JobMarketplaceTestWithdrawResume, test_withdraw_resume_4) {
    jobMarketplace.submit_resume("Amy", { "skill3", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    jobMarketplace.withdraw_resume(jobMarketplace.resumes[0]);
    jobMarketplace.withdraw_resume(jobMarketplace.resumes[0]);
    std::vector<Resume> expected = {};
    EXPECT_EQ(jobMarketplace.resumes, expected);
}

TEST_F(JobMarketplaceTestWithdrawResume, test_withdraw_resume_5) {
    jobMarketplace.submit_resume("Amy", { "skill1", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    jobMarketplace.withdraw_resume(jobMarketplace.resumes[0]);
    std::vector<Resume> expected = { {"John", {"skill3", "skill4"}, "experience"} };
    EXPECT_EQ(jobMarketplace.resumes, expected);
}

class JobMarketplaceTestSearchJobs : public ::testing::Test {
protected:
    JobMarketplace jobMarketplace;
};

TEST_F(JobMarketplaceTestSearchJobs, test_search_jobs) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill1", "skill2" });
    std::vector<Job> expected = { {"Software Engineer", "ABC Company", {"skill1", "skill2"}} };
    EXPECT_EQ(jobMarketplace.search_jobs("skill1"), expected);
}

TEST_F(JobMarketplaceTestSearchJobs, test_search_jobs_2) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill1", "skill2" });
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill3", "skill4" });
    std::vector<Job> expected = { {"Software Engineer", "ABC Company", {"skill1", "skill2"}} };
    EXPECT_EQ(jobMarketplace.search_jobs("skill1"), expected);
}

TEST_F(JobMarketplaceTestSearchJobs, test_search_jobs_3) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill1", "skill2" });
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill3", "skill4" });
    std::vector<Job> expected = { {"Software Engineer", "ABC Company", {"skill3", "skill4"}} };
    EXPECT_EQ(jobMarketplace.search_jobs("skill3"), expected);
}

TEST_F(JobMarketplaceTestSearchJobs, test_search_jobs_4) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill1", "skill2" });
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill3", "skill4" });
    std::vector<Job> expected = {};
    EXPECT_EQ(jobMarketplace.search_jobs("skill5"), expected);
}

TEST_F(JobMarketplaceTestSearchJobs, test_search_jobs_5) {
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill1", "skill2" });
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill3", "skill4" });
    std::vector<Job> expected = {};
    EXPECT_EQ(jobMarketplace.search_jobs("skill6"), expected);
}

class JobMarketplaceTestGetJobApplicants : public ::testing::Test {
protected:
    JobMarketplace jobMarketplace;
};

TEST_F(JobMarketplaceTestGetJobApplicants, test_get_job_applicants) {
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill1", "skill2" });
    std::vector<Resume> expected = { {"Tom", {"skill1", "skill2"}, "experience"} };
    EXPECT_EQ(jobMarketplace.get_job_applicants(jobMarketplace.job_listings[0]), expected);
}

TEST_F(JobMarketplaceTestGetJobApplicants, test_get_job_applicants_2) {
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill1", "skill2" });
    std::vector<Resume> expected = { {"Tom", {"skill1", "skill2"}, "experience"} };
    EXPECT_EQ(jobMarketplace.get_job_applicants(jobMarketplace.job_listings[0]), expected);
}

TEST_F(JobMarketplaceTestGetJobApplicants, test_get_job_applicants_3) {
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill3", "skill4" });
    std::vector<Resume> expected = { {"John", {"skill3", "skill4"}, "experience"} };
    EXPECT_EQ(jobMarketplace.get_job_applicants(jobMarketplace.job_listings[0]), expected);
}

TEST_F(JobMarketplaceTestGetJobApplicants, test_get_job_applicants_4) {
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill5", "skill6" });
    std::vector<Resume> expected = {};
    EXPECT_EQ(jobMarketplace.get_job_applicants(jobMarketplace.job_listings[0]), expected);
}

TEST_F(JobMarketplaceTestGetJobApplicants, test_get_job_applicants_5) {
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    jobMarketplace.submit_resume("John", { "skill3", "skill4" }, "experience");
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill6", "skill7" });
    std::vector<Resume> expected = {};
    EXPECT_EQ(jobMarketplace.get_job_applicants(jobMarketplace.job_listings[0]), expected);
}

class JobMarketplaceTestMatchesRequirements : public ::testing::Test {
protected:
    JobMarketplace jobMarketplace;
};

TEST_F(JobMarketplaceTestMatchesRequirements, test_matches_requirements) {
    Resume resume = { "Tom", {"skill1", "skill2"}, "experience" };
    std::vector<std::string> requirements = { "skill1", "skill2" };
    EXPECT_TRUE(jobMarketplace.matches_requirements(resume, requirements));
}

TEST_F(JobMarketplaceTestMatchesRequirements, test_matches_requirements_2) {
    Resume resume = { "Tom", {"skill1", "skill2"}, "experience" };
    std::vector<std::string> requirements = { "skill3", "skill4" };
    EXPECT_FALSE(jobMarketplace.matches_requirements(resume, requirements));
}

TEST_F(JobMarketplaceTestMatchesRequirements, test_matches_requirements_3) {
    Resume resume = { "Tom", {"skill1", "skill2"}, "experience" };
    std::vector<std::string> requirements = { "skill5", "skill6" };
    EXPECT_FALSE(jobMarketplace.matches_requirements(resume, requirements));
}

TEST_F(JobMarketplaceTestMatchesRequirements, test_matches_requirements_4) {
    Resume resume = { "Tom", {"skill1", "skill2"}, "experience" };
    std::vector<std::string> requirements = { "skill1", "skill3" };
    EXPECT_FALSE(jobMarketplace.matches_requirements(resume, requirements));
}

TEST_F(JobMarketplaceTestMatchesRequirements, test_matches_requirements_5) {
    Resume resume = { "Tom", {"skill1", "skill2"}, "experience" };
    std::vector<std::string> requirements = { "skill1" };
    EXPECT_FALSE(jobMarketplace.matches_requirements(resume, requirements));
}

class JobMarketplaceTestMain : public ::testing::Test {
protected:
    JobMarketplace jobMarketplace;
};

TEST_F(JobMarketplaceTestMain, test_main) {
    
    jobMarketplace.post_job("Software Engineer", "ABC Company", { "skill1", "skill2" });
    jobMarketplace.post_job("Mechanical Engineer", "XYZ Company", { "skill3", "skill4" });
    std::vector<Job> expected_jobs = {
        {"Software Engineer", "ABC Company", {"skill1", "skill2"}},
        {"Mechanical Engineer", "XYZ Company", {"skill3", "skill4"}}
    };
    EXPECT_EQ(jobMarketplace.job_listings, expected_jobs);

    
    jobMarketplace.remove_job(jobMarketplace.job_listings[1]);
    expected_jobs = {
        {"Software Engineer", "ABC Company", {"skill1", "skill2"}}
    };
    EXPECT_EQ(jobMarketplace.job_listings, expected_jobs);

    
    jobMarketplace.submit_resume("Tom", { "skill1", "skill2" }, "experience");
    std::vector<Resume> expected_resumes = {
        {"Tom", {"skill1", "skill2"}, "experience"}
    };
    EXPECT_EQ(jobMarketplace.resumes, expected_resumes);

    
    jobMarketplace.withdraw_resume(jobMarketplace.resumes[0]);
    std::vector<Resume> kkk;
    EXPECT_EQ(jobMarketplace.resumes, kkk);

    
    std::vector<Job> now{ {"Software Engineer", "ABC Company", { "skill1", "skill2" }} };
    EXPECT_EQ(jobMarketplace.search_jobs("skill1"),now);

    
    jobMarketplace.resumes = { {"Tom", {"skill1", "skill2"}, "experience"} };
    std::vector<Resume> ahaha{ {"Tom", { "skill1", "skill2" }, "experience"} };
    EXPECT_EQ(jobMarketplace.get_job_applicants(jobMarketplace.job_listings[0]),ahaha);

    
    Resume resume{ "Tom", { "skill1", "skill2" }, "experience" };
    std::vector<std::string> required_skills = { "skill1", "skill2" };
    EXPECT_TRUE(jobMarketplace.matches_requirements(resume, required_skills));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}