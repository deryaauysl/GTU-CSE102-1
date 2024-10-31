#include <stdio.h>
#include <stdlib.h>
#include <math.h> /* include -lm when we compiling , because of the library */

#define X 0.001 /* defining macro variables*/
#define N 5

double finding_distance(double px, double py, double cx, double cy) /*function to calculating distances between points*/
{
    double distance;
    distance = sqrt(pow(px - cx, 2) + pow(py - cy, 2));

    return distance;
}

double finding_x_percentage(double mindist, double middist) /*function to calculating percentage difference between medium and minimum point*/
{

    double percentdifference = fabs(mindist - middist) / fabs((mindist + middist) / 2); /* percentage difference formula*/

    return percentdifference;
}

int main()
{
    double cx1 = 0, cy1 = 0, cx2 = 0, cy2 = 0, cx3 = 0, cy3 = 0; /* center poins of three clusters*/
    double pointx, pointy;                                       /*new added point*/
    double dist1, dist2, dist3;                                  /*distances*/
    double maxd, midd, mind;                                     /* maximum distance , medium distance , minimum distance */
    double percdif;
    int i = 0;
    int n1 = 1; /* numbers of points*/
    int n2 = 1;
    int n3 = 1;

    /*printf("Enter the 3 clusters coordinates (x y): \n"); */

    scanf("%lf %lf", &cx1, &cy1); /* Taking 3 cluster's center's point*/
    scanf("%lf %lf", &cx2, &cy2);
    scanf("%lf %lf", &cx3, &cy3);

    for (i = 0; i < N; i++)
    {

        /*printf("Enter the point\n");*/
        scanf("%lf %lf", &pointx, &pointy); /*taking a point*/

        dist1 = finding_distance(pointx, pointy, cx1, cy1); /* calculate distances*/
        dist2 = finding_distance(pointx, pointy, cx2, cy2);
        dist3 = finding_distance(pointx, pointy, cx3, cy3);

        if (dist1 >= dist2 && dist1 >= dist3) /* comparing values for finding maximum,medium and minimum values*/
        {
            maxd = dist1;
            if (dist2 >= dist3)
            {
                midd = dist2;
                mind = dist3;
            }
            else
            {
                midd = dist3;
                mind = dist2;
            }
        }
        else if (dist2 >= dist1 && dist2 >= dist3)
        {
            maxd = dist2;
            if (dist1 >= dist3)
            {
                midd = dist1;
                mind = dist3;
            }
            else
            {
                midd = dist3;
                mind = dist1;
            }
        }

        else
        {
            maxd = dist3;
            if (dist2 >= dist1)
            {
                midd = dist2;
                mind = dist1;
            }
            else
            {
                midd = dist1;
                mind = dist2;
            }
        }

        percdif = finding_x_percentage(mind, midd); /* finding percentage difference*/

        if (percdif < X) /* If there is less than X percent difference, discarding the point.*/
        {
            printf("Point (%lf,%lf) was discarded.\n", pointx, pointy);
        }
        else /*Else, include the point in which cluster belong to*/
        {
            if (mind == dist1) /*Which distances is minimum, the point include there*/
            {
                printf("Point (%lf,%lf) was included in Cluster 1\n", pointx, pointy);
                n1++; /* increasing number of points in cluster 1*/
                cx1 = (cx1 * n1 + pointx) / (n1 + 1);
                cy1 = (cy1 * n1 + pointy) / (n1 + 1); /* calculating new center of cluster and update the coordinates*/
            }
            else if (mind == dist2)
            {
                printf("Point (%lf,%lf) was included in Cluster 2\n", pointx, pointy);
                n2++; /* increasing number of points in cluster 2*/
                cx2 = (cx2 * n2 + pointx) / (n2 + 1);
                cy2 = (cy2 * n2 + pointy) / (n2 + 1); /* calculating new center of cluster and update coordinates*/
            }
            else if (mind == dist3)
            {
                printf("Point (%lf,%lf) was included in Cluster 3\n", pointx, pointy);
                n3++; /* increasing number of points in cluster 3*/
                cx3 = (cx3 * n3 + pointx) / (n3 + 1);
                cy3 = (cy3 * n3 + pointy) / (n3 + 1); /* calculating new center of cluster and update coordinates*/
            }
        }
    }

    printf("Cluster 1: %lf,%lf,%d \n", cx1, cy1, n1); /* printing every cluster's center coordinates and number of points*/
    printf("Cluster 2: %lf,%lf,%d \n", cx2, cy2, n2);
    printf("Cluster 3: %lf,%lf,%d \n", cx3, cy3, n3);

    return 0;
}
