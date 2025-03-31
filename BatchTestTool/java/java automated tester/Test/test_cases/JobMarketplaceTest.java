package test_cases;
import to_be_tested.JobMarketplace;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class JobMarketplaceTest {

    private JobMarketplace jobMarketplace;

    @BeforeEach
    public void setUp() {
        jobMarketplace = new JobMarketplace();
    }

    @Test
    public void testPostJob() {
        jobMarketplace.postJob("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"));
        assertEquals(jobMarketplace.getJobListings(), Arrays.asList(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"))));
    }

    @Test
    public void testPostJob2() {
        jobMarketplace.postJob("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4"));
        assertEquals(jobMarketplace.getJobListings(), Arrays.asList(new JobMarketplace.JobListing("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4"))));
    }

    @Test
    public void testPostJob3() {
        jobMarketplace.postJob("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"));
        jobMarketplace.postJob("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4"));
        assertEquals(jobMarketplace.getJobListings(), Arrays.asList(
                new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2")),
                new JobMarketplace.JobListing("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4"))
        ));
    }

    @Test
    public void testPostJob4() {
        jobMarketplace.postJob("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"));
        jobMarketplace.postJob("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4"));
        jobMarketplace.postJob("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"));
        assertEquals(jobMarketplace.getJobListings(), Arrays.asList(
                new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2")),
                new JobMarketplace.JobListing("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4")),
                new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"))
        ));
    }

    @Test
    public void testPostJob5() {
        jobMarketplace.postJob("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"));
        jobMarketplace.postJob("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4"));
        jobMarketplace.postJob("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"));
        jobMarketplace.postJob("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4"));
        assertEquals(jobMarketplace.getJobListings(), Arrays.asList(
                new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2")),
                new JobMarketplace.JobListing("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4")),
                new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2")),
                new JobMarketplace.JobListing("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4"))
        ));
    }

    @Test
    public void testRemoveJob() {
        JobMarketplace.JobListing job = new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"));
        jobMarketplace.getJobListings().add(job);
        jobMarketplace.removeJob(job);
        assertEquals(jobMarketplace.getJobListings(), Arrays.asList());
    }

    @Test
    public void testRemoveJob2() {
        JobMarketplace.JobListing job1 = new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"));
        JobMarketplace.JobListing job2 = new JobMarketplace.JobListing("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4"));
        jobMarketplace.getJobListings().add(job1);
        jobMarketplace.getJobListings().add(job2);
        jobMarketplace.removeJob(job1);
        assertEquals(jobMarketplace.getJobListings(), Arrays.asList(job2));
    }

    @Test
    public void testRemoveJob3() {
        JobMarketplace.JobListing job1 = new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"));
        JobMarketplace.JobListing job2 = new JobMarketplace.JobListing("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4"));
        jobMarketplace.getJobListings().add(job1);
        jobMarketplace.getJobListings().add(job2);
        jobMarketplace.removeJob(job1);
        jobMarketplace.removeJob(job2);
        assertEquals(jobMarketplace.getJobListings(), Arrays.asList());
    }

    @Test
    public void testRemoveJob4() {
        JobMarketplace.JobListing job1 = new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"));
        JobMarketplace.JobListing job2 = new JobMarketplace.JobListing("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4"));
        JobMarketplace.JobListing job3 = new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"));
        jobMarketplace.getJobListings().add(job1);
        jobMarketplace.getJobListings().add(job2);
        jobMarketplace.getJobListings().add(job3);
        jobMarketplace.removeJob(job1);
        jobMarketplace.removeJob(job2);
        assertEquals(jobMarketplace.getJobListings(), Arrays.asList(job3));
    }

    @Test
    public void testRemoveJob5() {
        JobMarketplace.JobListing job1 = new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"));
        JobMarketplace.JobListing job2 = new JobMarketplace.JobListing("Mechanical Engineer", "XYZ Company", Arrays.asList("requirement3", "requirement4"));
        JobMarketplace.JobListing job3 = new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("requirement1", "requirement2"));
        jobMarketplace.getJobListings().add(job1);
        jobMarketplace.getJobListings().add(job2);
        jobMarketplace.getJobListings().add(job3);
        jobMarketplace.removeJob(job1);
        assertEquals(jobMarketplace.getJobListings(), Arrays.asList(job2, job3));
    }

    @Test
    public void testSubmitResume() {
        jobMarketplace.submitResume("Tom", Arrays.asList("skill1", "skill2"), "experience");
        assertEquals(jobMarketplace.getResumes(), Arrays.asList(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience")));
    }

    @Test
    public void testSubmitResume2() {
        jobMarketplace.submitResume("Tom", Arrays.asList("skill1", "skill2"), "experience");
        jobMarketplace.submitResume("John", Arrays.asList("skill3", "skill4"), "experience");
        assertEquals(jobMarketplace.getResumes(), Arrays.asList(
                new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"),
                new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience")
        ));
    }

    @Test
    public void testSubmitResume3() {
        jobMarketplace.submitResume("Tom", Arrays.asList("skill1", "skill2"), "experience");
        jobMarketplace.submitResume("John", Arrays.asList("skill3", "skill4"), "experience");
        jobMarketplace.submitResume("Tom", Arrays.asList("skill1", "skill2"), "experience");
        assertEquals(jobMarketplace.getResumes(), Arrays.asList(
                new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"),
                new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience"),
                new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience")
        ));
    }

    @Test
    public void testSubmitResume4() {
        jobMarketplace.submitResume("Tom", Arrays.asList("skill1", "skill2"), "experience");
        jobMarketplace.submitResume("John", Arrays.asList("skill3", "skill4"), "experience");
        jobMarketplace.submitResume("Tom", Arrays.asList("skill1", "skill2"), "experience");
        jobMarketplace.submitResume("John", Arrays.asList("skill3", "skill4"), "experience");
        assertEquals(jobMarketplace.getResumes(), Arrays.asList(
                new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"),
                new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience"),
                new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"),
                new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience")
        ));
    }

    @Test
    public void testSubmitResume5() {
        jobMarketplace.submitResume("Tom", Arrays.asList("skill1", "skill2"), "experience");
        jobMarketplace.submitResume("John", Arrays.asList("skill3", "skill4"), "experience");
        jobMarketplace.submitResume("Tom", Arrays.asList("skill1", "skill2"), "experience");
        jobMarketplace.submitResume("John", Arrays.asList("skill3", "skill4"), "experience");
        jobMarketplace.submitResume("Tom", Arrays.asList("skill1", "skill2"), "experience");
        assertEquals(jobMarketplace.getResumes(), Arrays.asList(
                new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"),
                new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience"),
                new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"),
                new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience"),
                new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience")
        ));
    }

    @Test
    public void testWithdrawResume() {
        JobMarketplace.Resume resume = new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience");
        jobMarketplace.getResumes().add(resume);
        jobMarketplace.withdrawResume(resume);
        assertEquals(jobMarketplace.getResumes(), Arrays.asList());
    }

    @Test
    public void testWithdrawResume2() {
        JobMarketplace.Resume resume1 = new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience");
        JobMarketplace.Resume resume2 = new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience");
        jobMarketplace.getResumes().add(resume1);
        jobMarketplace.getResumes().add(resume2);
        jobMarketplace.withdrawResume(resume1);
        assertEquals(jobMarketplace.getResumes(), Arrays.asList(resume2));
    }

    @Test
    public void testWithdrawResume3() {
        JobMarketplace.Resume resume1 = new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience");
        JobMarketplace.Resume resume2 = new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience");
        jobMarketplace.getResumes().add(resume1);
        jobMarketplace.getResumes().add(resume2);
        jobMarketplace.withdrawResume(resume1);
        jobMarketplace.withdrawResume(resume2);
        assertEquals(jobMarketplace.getResumes(), Arrays.asList());
    }

    @Test
    public void testWithdrawResume4() {
        JobMarketplace.Resume resume1 = new JobMarketplace.Resume("Amy", Arrays.asList("skill3", "skill2"), "experience");
        JobMarketplace.Resume resume2 = new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience");
        jobMarketplace.getResumes().add(resume1);
        jobMarketplace.getResumes().add(resume2);
        jobMarketplace.withdrawResume(resume1);
        jobMarketplace.withdrawResume(resume2);
        assertEquals(jobMarketplace.getResumes(), Arrays.asList());
    }

    @Test
    public void testWithdrawResume5() {
        JobMarketplace.Resume resume1 = new JobMarketplace.Resume("Amy", Arrays.asList("skill1", "skill2"), "experience");
        JobMarketplace.Resume resume2 = new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience");
        jobMarketplace.getResumes().add(resume1);
        jobMarketplace.getResumes().add(resume2);
        jobMarketplace.withdrawResume(resume1);
        assertEquals(jobMarketplace.getResumes(), Arrays.asList(resume2));
    }

    @Test
    public void testSearchJobs() {
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill1", "skill2")));
        assertEquals(jobMarketplace.searchJobs("skill1"), Arrays.asList(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill1", "skill2"))));
    }

    @Test
    public void testSearchJobs2() {
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill1", "skill2")));
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill3", "skill4")));
        assertEquals(jobMarketplace.searchJobs("skill1"), Arrays.asList(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill1", "skill2"))));
    }

    @Test
    public void testSearchJobs3() {
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill1", "skill2")));
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill3", "skill4")));
        assertEquals(jobMarketplace.searchJobs("skill3"), Arrays.asList(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill3", "skill4"))));
    }

    @Test
    public void testSearchJobs4() {
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill1", "skill2")));
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill3", "skill4")));
        assertEquals(jobMarketplace.searchJobs("skill5"), Arrays.asList());
    }

    @Test
    public void testSearchJobs5() {
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill1", "skill2")));
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill3", "skill4")));
        assertEquals(jobMarketplace.searchJobs("skill6"), Arrays.asList());
    }

    @Test
    public void testGetJobApplicants() {
        jobMarketplace.getResumes().add(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"));
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill1", "skill2")));
        assertEquals(jobMarketplace.getJobApplicants(jobMarketplace.getJobListings().get(0)), Arrays.asList(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience")));
    }

    @Test
    public void testGetJobApplicants2() {
        jobMarketplace.getResumes().add(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"));
        jobMarketplace.getResumes().add(new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience"));
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill1", "skill2")));
        assertEquals(jobMarketplace.getJobApplicants(jobMarketplace.getJobListings().get(0)), Arrays.asList(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience")));
    }

    @Test
    public void testGetJobApplicants3() {
        jobMarketplace.getResumes().add(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"));
        jobMarketplace.getResumes().add(new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience"));
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill3", "skill4")));
        assertEquals(jobMarketplace.getJobApplicants(jobMarketplace.getJobListings().get(0)), Arrays.asList(new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience")));
    }

    @Test
    public void testGetJobApplicants4() {
        jobMarketplace.getResumes().add(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"));
        jobMarketplace.getResumes().add(new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience"));
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill5", "skill6")));
        assertEquals(jobMarketplace.getJobApplicants(jobMarketplace.getJobListings().get(0)), Arrays.asList());
    }

    @Test
    public void testGetJobApplicants5() {
        jobMarketplace.getResumes().add(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"));
        jobMarketplace.getResumes().add(new JobMarketplace.Resume("John", Arrays.asList("skill3", "skill4"), "experience"));
        jobMarketplace.getJobListings().add(new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill6", "skill7")));
        assertEquals(jobMarketplace.getJobApplicants(jobMarketplace.getJobListings().get(0)), Arrays.asList());
    }

    @Test
    public void testMatchesRequirements() {
        assertTrue(jobMarketplace.matchesRequirements(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"), Arrays.asList("skill1", "skill2")));
    }

    @Test
    public void testMatchesRequirements2() {
        assertFalse(jobMarketplace.matchesRequirements(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"), Arrays.asList("skill3", "skill4")));
    }

    @Test
    public void testMatchesRequirements3() {
        assertFalse(jobMarketplace.matchesRequirements(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"), Arrays.asList("skill5", "skill6")));
    }

    @Test
    public void testMatchesRequirements4() {
        assertFalse(jobMarketplace.matchesRequirements(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"), Arrays.asList("skill1", "skill3")));
    }

    @Test
    public void testMatchesRequirements5() {
        assertFalse(jobMarketplace.matchesRequirements(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"), Arrays.asList("skill1")));
    }

    @Test
    public void testMain() {
        jobMarketplace.postJob("Software Engineer", "ABC Company", Arrays.asList("skill1", "skill2"));
        jobMarketplace.postJob("Mechanical Engineer", "XYZ Company", Arrays.asList("skill3", "skill4"));
        assertEquals(jobMarketplace.getJobListings(), Arrays.asList(
                new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill1", "skill2")),
                new JobMarketplace.JobListing("Mechanical Engineer", "XYZ Company", Arrays.asList("skill3", "skill4"))
        ));
        jobMarketplace.removeJob(jobMarketplace.getJobListings().get(1));
        assertEquals(jobMarketplace.getJobListings(), Arrays.asList(
                new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill1", "skill2"))
        ));
        jobMarketplace.submitResume("Tom", Arrays.asList("skill1", "skill2"), "experience");
        assertEquals(jobMarketplace.getResumes(), Arrays.asList(
                new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience")
        ));
        jobMarketplace.withdrawResume(jobMarketplace.getResumes().get(0));
        assertEquals(jobMarketplace.getResumes(), Arrays.asList());
        assertEquals(jobMarketplace.searchJobs("skill1"), Arrays.asList(
                new JobMarketplace.JobListing("Software Engineer", "ABC Company", Arrays.asList("skill1", "skill2"))
        ));
        jobMarketplace.getResumes().add(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"));
        assertEquals(jobMarketplace.getJobApplicants(jobMarketplace.getJobListings().get(0)), Arrays.asList(
                new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience")
        ));
        assertTrue(jobMarketplace.matchesRequirements(new JobMarketplace.Resume("Tom", Arrays.asList("skill1", "skill2"), "experience"), Arrays.asList("skill1", "skill2")));
    }
}